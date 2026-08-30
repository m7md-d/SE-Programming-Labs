package main

import (
	"database/sql"
	"log"

	_ "modernc.org/sqlite"
)

func initDB() *sql.DB {
	db, err := sql.Open("sqlite", "chat.db")
	if err != nil {
		log.Fatal(err)
	}

	query := `
		CREATE TABLE IF NOT EXISTS messages (
			id INTEGER PRIMARY KEY AUTOINCREMENT,
			username TEXT NOT NULL,
			content TEXT NOT NULL
		)
	`
	_, err = db.Exec(query)
	if err != nil {
		log.Fatal(err)
	}
	return db
}