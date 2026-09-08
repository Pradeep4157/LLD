package main

import (
	"fmt"
	"http"
	"io"
)	

func main() {
	// here i remember that we used to define the end points..
	http.HandleFunc("/job", handleJob)
	http.ListenAndServe(":8080", nil)
}

func handleJob(w http.ResponseWriter, r *http.Request) {
	fmt.Println("handleJob is called")
	body, err := io.ReadAll(r.Body)
	if err != nil {
		http.Error(w, "some error has occured", http.StatusBadRequest)
		return
	}

}