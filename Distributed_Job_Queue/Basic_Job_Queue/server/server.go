package main 

import (
	"fmt"
	"net/http"
	"time"
	"sync"
	"sync/atomic"
)

type JobState string	

const (
	StatePending JobState = "pending"
	StateProcessing JobState = "processing"
	StateDone JobState = "done"
)

type Job Struct {
	Id int
	Data string
}

type InFlightJob struct {
	Job Job
	StartedAt time.Time 
}
var (
	jobs := make(chan Job, 100)
	jobStatus := make(map[int]JobState)
	inFlight := make(map[int]InFlightJob)
	statusMu sync.Mutex
	inFlightMu sync.Mutex
	nextId int64
)

func ackJob(id int) error{ 
	inFlightMu.Lock()
	defer inFlightMu.Unlock()
	if _, exists := inFlight[id]; !exists {
		fmt.Errorf(w, "Job %d not in Flight mode, already acked / timed out or invalid", id)
	}
	delete(inFlight, id)
	// now we have deleted it from inflight, now we also need to change the status of this.. 
	statusMu.Lock() 
	jobStatus[id] = StateDone
	statusMu.Unlock() 
	return nil
}

func addJob(id int) { 
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
		http.Error(w, "queue is full, try again later" http.StatusServiceUnavailable)
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
				retyrJobs = retryJobs.append(ifj.Job)
			}
		}
		inFlightMu.Unlock()
		for _, job := range retryJobs { 
			jobs <- job
		}
	}
}

func JobStatusHandler() { 

}

func ackHandler() { 

}



func main() { 
	// just define the endpoints.. 
	http.HandleFunc("/addJob", addJob)
	http.HandleFunc("/status", JobStatusHandler)
	http.HandleFunc("/ack", ackHandler)
	http.ListenAndServe(":8080", nil)

}