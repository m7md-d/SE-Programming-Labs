package main

import "database/sql"

func SaveMessage(db *sql.DB, message Message) error {
	query := `
		INSERT INTO messages (username, content)
		VALUES (?, ?)
	`

	_, err := db.Exec(query, message.Username, message.Content)
	return err
}

func GetMessages(db *sql.DB) ([]Message, error) {
	rows, err := db.Query(`
		SELECT id, username, content
		FROM messages
		ORDER BY id ASC
	`)
	if err != nil {
		return nil, err
	}
	defer rows.Close()

	var messages []Message

	for rows.Next() {
		var message Message

		err := rows.Scan(
			&message.ID,
			&message.Username,
			&message.Content,
		)
		if err != nil {
			return nil, err
		}

		messages = append(messages, message)
	}

	if err := rows.Err(); err != nil {
		return nil, err
	}

	return messages, nil
}