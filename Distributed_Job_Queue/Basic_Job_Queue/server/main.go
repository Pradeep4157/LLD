// every go file belongs to package, main means that it is an executable program.. 
package main
// fmt is for printing things and http is for creating an http server..
import (
	"fmt"
	"net/http"
	"io"
)
var jobQueue []string
func main() {
	// when any request comes on /job handleJob function is going to be executed.. 
	http.HandleFunc("/job", handleJob)
	// just printing on console..
	fmt.Println("Queue Server running on port 8080")
	// starts server on port 8080
	http.ListenAndServe(":8080", nil)
}

// function is executed whenever any request comes on /job endpoint..
// r is info regarding incoming request, w allows us to send some response back to client.. 
func handleJob(w http.ResponseWriter, r *http.Request) {
	fmt.Println("Received a Job!")

	body, err := io.ReadAll(r.Body)
	if err != nil {
		http.Error(w, "Failed to read request", http.StatusBadRequest)
		return
	}
	job := string(body)
	jobQueue = append(jobQueue, job)

	// here we are sending the response back to client, []byte is just that we convert the string in response as
	// array of byte and return.. 
	w.Write([]byte("Job received"))
}
