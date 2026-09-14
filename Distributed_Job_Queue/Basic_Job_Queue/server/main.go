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

type Job struct {
	Id int
	Data string
}

var (
	jobs = make(chan Job, 100)
	jobStatus = make(map[int]JobState)
	statusMu sync.Mutex
	nextId int64
)

func addJob(w http.ResponseWriter, r *http.Request) {
	// we just take the global nextId variable and use that to assign new job id 
	// to this new incoming job..
	id := int(atomic.AddInt64(&nextId, 1))
	// now we use this id to add a new job to the map.. 
	statusMu.Lock()
	jobStatus[id] = StatePending
	statusMu.Unlock()
	// adding this job to the go channel..
	select {

	case jobs <- Job{ Id: id, Data: "new_job"}:
		fmt.Fprintf(w, "Job added id = %d", id)
	default:
		statusMu.Lock()
		delete(jobStatus,id)
		statusMu.Unlock()
		http.Error(w, "queue is full, try again later", http.StatusServiceUnavailable)
	}
}
func worker(workerId int) {
	// its going to wait in front of the go channel if it gets some job
	// it will process and just update the status to done..
	for job := range jobs {
		// we need to update the map that we are processing this job..
		statusMu.Lock()
		jobStatus[job.Id] = StateProcessing
		statusMu.Unlock()
		// now i will process it parallely..
		fmt.Printf("Worker %d, is procesing Job with id : %d\n",workerId, job.Id)
		time.Sleep(50 * time.Millisecond)
		statusMu.Lock()
		jobStatus[job.Id] = StateDone
		statusMu.Unlock()
		fmt.Printf("Worker %d has completed processing Job with id : %d\n", workerId, job.Id)

	}
}

func JobStatusHandler(w http.ResponseWriter, r * http.Request) {
	idStr := r.URL.Query().Get("id")
	var id int
	_, err := fmt.Sscanf(idStr,"%d", &id)
	if err != nil {
		http.Error(w, "Error parsing the id", http.StatusBadRequest)
		return
	}
	//  now we have the id .. 
	// now we will search that id in map... 
	statusMu.Lock()
	state, exists := jobStatus[id]
	statusMu.Unlock()
	if !exists {
		http.Error(w, "id not found", http.StatusNotFound)
		return
	}
	// now we just return the state.. 
	fmt.Fprintf(w, "Job %d : %s", id, state)
}
func main() { 
	// first i think we need to start some worker go routines.. 
	fmt.Println("Server has Started!!")
	for i := 1; i <= 3; i++ {
		go worker(i)
	}
	fmt.Println("All the workers have been created !!")
	http.HandleFunc("/addjob", addJob)
	http.HandleFunc("/status", JobStatusHandler)
	http.ListenAndServe(":8080", nil)
}
