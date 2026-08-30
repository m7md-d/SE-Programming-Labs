package main

import (
	"database/sql"
	"encoding/json"
	"net/http"
)

func messagesHandler(db *sql.DB) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		switch r.Method {
		case http.MethodGet:
			getMessages(w, db)

		default:
			http.Error(w, "method not allowed", http.StatusMethodNotAllowed)
		}
	}
}

func getMessages(w http.ResponseWriter, db *sql.DB) {
	messages, err := GetMessages(db)
	if err != nil {
		http.Error(w, "failed to get messages", http.StatusInternalServerError)
		return
	}

	w.Header().Set("Content-Type", "application/json")

	/* اسلوب شائع بين مطورين اللغة للتعامل مع الخطأ */
	if err := json.NewEncoder(w).Encode(messages); err != nil {
		http.Error(w, "failed to encode messages", http.StatusInternalServerError)
	}
}
