package main

import (
	"fmt"
	"log"
	"net/http"
)

func main() {
	db := initDB()
	defer db.Close()

	http.HandleFunc("/messages", messagesHandler(db))

	fmt.Println("server running on http://localhost:8080")

	log.Fatal(http.ListenAndServe(":8080", nil))
}
