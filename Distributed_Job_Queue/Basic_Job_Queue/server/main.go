package main

import (
	"fmt"
	"net/http"
	"time"

)
// it will allow only 100 http requests buffer when all go routines are busy,
// when an 101th request comes and still all worker threads / goroutines are
// busy it would block the incoming HTTP request..
var jobs = make(chan string, 100)

func worker(id int) {
// channel is like an open ended pipe, range jobs means that keep waiting 
// for the next value forever. If the channel is empty block and sleep until
// some new value arrives or someone explicitely closes the channel 	
	for job := range jobs {
		fmt.Printf("Worker %d: Processing %s\n", id, job)
		time.Sleep(500 * time.Millisecond)
		fmt.Printf("Worker %d finished job %s\n", id, job)
	}
}

func addJob(w http.ResponseWriter, r *http.Request) {
	body, err := r.body()
	if err != nil {
		http.Error(w, "failed to read job", http.StatusBadRequest)
		return
	}
	jobs <- string(body)
	w.Write([]byte("Job added"))
}

func main() { 
	for i:= 1; i <= 3; i++ {
		go worker(i)
	}
	http.HandleFunc("/addJob", addJob)
	http.ListenAndServe(":8080", nil)

}