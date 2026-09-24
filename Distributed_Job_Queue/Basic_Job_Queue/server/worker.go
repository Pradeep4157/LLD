package main 

import (
	"fmt"
	"net/http"
	"time"
	"encoding/json"
)

type Job struct {
	Id int
	Data string
}

func main() { 
	// we will send get request to get the job id for processing.. 
	for{
		resp, err := http.Get("http://localhost:8080/get-job")
		if err != nil {
			fmt.Println("Error contacting Server: ", err)
			time.Sleep(1 * time.Second)
			continue
		}
		// now maybe we dont have any job to process.. 
		if resp.StatusCode == http.StatusNoContent { 
			resp.Body.Close() 
			time.Sleep(1 * time.Second)
			continue
		} 
		// now we complete the job..
		var job Job
		json.NewDecoder(resp.Body).Decode(&job)
		fmt.Println("got job : ", job.Id)
		time.Sleep(500 * time.Millisecond)
		resp.Body.Close()
		http.Post(fmt.Sprintf("http://localhost:8080/ack?id=%d", job.Id), "", nil)
	}
}