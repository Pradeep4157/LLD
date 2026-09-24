package main 

import (
	"fmt"
	"net/http"
	"time"
	"sync"
	"sync/atomic"
	"encoding/json"
)

type JobState string	

const (
	StatePending JobState = "pending"
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
	jobs = make(chan Job, 100)
	jobStatus = make(map[int]JobState)
	inFlight = make(map[int]InFlightJob)
	statusMu sync.Mutex
	inFlightMu sync.Mutex
	nextId int64
)

func ackJob(id int) error{ 
	inFlightMu.Lock()
	defer inFlightMu.Unlock()
	if _, exists := inFlight[id]; !exists {
		return fmt.Errorf( "Job %d not in Flight mode, already acked / timed out or invalid", id)
	}
	delete(inFlight, id)
	// now we have deleted it from inflight, now we also need to change the status of this.. 
	statusMu.Lock() 
	jobStatus[id] = StateDone
	statusMu.Unlock() 
	return nil
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
		statusMu.Lock()
		delete(jobStatus, id)
		statusMu.Unlock()
		http.Error(w, "queue is full, try again later", http.StatusServiceUnavailable)
	}
}

func watchDog() { 
	for {
		time.Sleep(2 * time.Second)	
		var retryJobs []Job
		inFlightMu.Lock()
		for id, ifj := range inFlight {
			if time.Since(ifj.StartedAt) > 5 * time.Second {
				fmt.Printf("Job %d left hanging for too long maybe because worker thread is dead", id)
				delete(inFlight, id)
				retryJobs = append(retryJobs, ifj.Job)
			}
		}
		inFlightMu.Unlock()
		for _, job := range retryJobs { 
			jobs <- job
		}
	}
}
// it takes id from url and then tells the status of that job id..
func JobStatusHandler(w http.ResponseWriter, r *http.Request) { 
	idStr := r.URL.Query().Get("id")
	var id int 
	// now we parse the string -> int.. 
	_, err := fmt.Sscanf(idStr, "%d", &id)
	if err != nil { 
		http.Error(w, "Error while parsing id", http.StatusBadRequest)
		return
	}
	// now we have id, we just return the status of the job,, 
	statusMu.Lock()
	state, exists := jobStatus[id]
	statusMu.Unlock()
	if !exists { 
		http.Error(w, "Did not find the job in queue, either it has been completed or timedOut", http.StatusNotFound)
		return
	}
	fmt.Fprintf(w, "job %d : %s", id, state)
}

// ext request to ack some job..
func ackHandler(w http.ResponseWriter, r *http.Request) { 
	idStr := r.URL.Query().Get("id")
	var id int 
	_, err := fmt.Sscanf(idStr, "%d", &id)
	if err != nil {
		http.Error(w, "Error while parsing Job id", http.StatusBadRequest)
		return
	}
	// now we will use ackJob to ack this.. 
	if err := ackJob(id); err != nil {
		http.Error(w, err.Error(), http.StatusConflict)
		return
	}
	fmt.Fprintf(w, "job %d acked", id)
}

func getJobHandler(w http.ResponseWriter, r *http.Request) {
	select {
	case job := <-jobs:  
		inFlightMu.Lock() 
		inFlight[job.Id] = InFlightJob{ Job: job, StartedAt : time.Now()}
		inFlightMu.Unlock()
		statusMu.Lock()
		jobStatus[job.Id] = StateProcessing
		statusMu.Unlock()
		w.Header().Set("Content-Type","application/json")
		json.NewEncoder(w).Encode(job)
	default:
		w.WriteHeader(http.StatusNoContent)
	}
}

func main() { 
	// just define the endpoints.. 
	http.HandleFunc("/addJob", addJob)
	http.HandleFunc("/status", JobStatusHandler)
	http.HandleFunc("/ack", ackHandler)
	http.HandleFunc("/get-job", getJobHandler)
	http.ListenAndServe(":8080", nil)

}