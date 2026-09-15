package main

import (
	"net/http"
	"fmt"
	"time"
	"sync"
	"sync/atomic"
)

type JobState string 

const (
	StatePending JobState  = "pending"
	StateProcessing JobState = "processing"
	StateDone JobState = "done"
)

type Job struct {
	Id int
	Data string 
}

type InFlightJob struct {
	Job Job 
	StartedAt time.Time
}
var (
	inFlight = make(map[int]InFlightJob)
	inFlightMu sync.Mutex
	jobs = make(chan Job, 100)
	jobStatus = make(map[int]JobState)
	statusMu sync.Mutex
	nextId int64
)

// now i define the worker..

func worker(id int) {
	for job := range jobs {
		// i add it to inflight..
		inFlightMu.Lock()
		inFlight[job.Id] = InFlightJob{Job : job, StartedAt: time.Now()}
		inFlightMu.Unlock()

		statusMu.Lock()
		jobStatus[job.Id] = StateProcessing
		statusMu.Unlock()

		fmt.Printf("Worker %d is processing job : %d", id, job.Id)
		time.Sleep(500 * time.Millisecond)

		// job done !!
		inFlightMu.Lock()
		delete(inFlight, job.Id)
		inFlightMu.Unlock()

		statusMu.Lock()
		jobStatus[job.Id] = StateDone
		statusMu.Unlock()

		fmt.Printf("Worker %d finished job %d\n", id, job.Id)

	}
}

func watchdog() { 
	// if any job is there for a very long time then it will mark it as failed and queue that job again.. 
	for { 
		// infinite loop.. 
		// putting it to sleep for 2 seconds so that it doesnt eat up the cpu resources.. 
		time.Sleep(2 * time.Second)
		var retryJobs []Job
		inFlightMu.Lock()
		// now i try to find any job left hanging.. 
		for id, ifj := range inFlight {
			if time.Since(ifj.StartedAt) > 5 * time.Second {
				// it is left hanging.. 
				fmt.Printf("Job %d left hanging maybe because its worker thread is dead, requeing\n ", id)
				retryJobs = append(retryJobs, ifj.Job)
				// now we need to send request to add this job again to the channel.. 
				delete(inFlight, id)
				// jobs <- ifj.Job
			}
		}
		inFlightMu.Unlock()
		for _, job := range retryJobs { 
			jobs <- job
		}
	}
}

func addJob(w http.ResponseWriter, r *http.Request) {
	id := int(atomic.AddInt64(&nextId, 1))

	statusMu.Lock()
	jobStatus[id] = StatePending
	statusMu.Unlock()	
	select {
	case jobs <- Job{Id: id, Data: "new_job"}:
		fmt.Fprintf(w, "Job %d added to queue", id)
	default:
		// queue was full we couldnt add it.. 
		statusMu.Lock()
		delete(jobStatus, id)
		statusMu.Unlock()
		http.Error(w, "queue is full, try again later", http.StatusServiceUnavailable)
	}
}

func JobStatusHandler(w http.ResponseWriter, r *http.Request) {
	idStr := r.URL.Query().Get("id")
	var id int
	_, err := fmt.Sscanf(idStr, "%d", &id)
	if err != nil { 
		http.Error(w,"Could not parse id", http.StatusBadRequest)
		return
	}
	// now we have id,  now we check status in jobStatus.. 
	statusMu.Lock()
	state, exists := jobStatus[id] 
	statusMu.Unlock()

	if !exists { 
		http.Error(w, "id not Found", http.StatusNotFound)
		return
	}
	fmt.Fprintf(w, "Job %d : %s", id, state)
}

func main() { 
	for i := 1; i <= 3; i++ { 
		go worker(i)
	}
	fmt.Println("All workers have been  deployed")
	go watchdog() 
	fmt.Println("Watchdog has been deployed")
	http.HandleFunc("/addjob", addJob)
	http.HandleFunc("/status", JobStatusHandler)
	http.ListenAndServe(":8080", nil)
}