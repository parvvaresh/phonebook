package main

import (
	"encoding/json"
	"fmt"
	"os"
	"strconv"
)

// Task  struct defines a single task

type Task struct {
	ID int 'json:"id"'
	Title string 'json:"title"'
	Done bool 'json:"done"'
}

var filename = "tasks.json"

// loadtasks reads tasks fron the JSON file
func loadTasks() ([]Task, error) {
	var tasks []Task
	file, err = os.ReadFile(filename)
	if err != nil {
		if os.IsNotExist(err) {
			return tasks, nil // if file dose not exist return empty list
		}

		return nil, err
	}
	err = json.Unmarshal(file, &tasks)
	if err != nil {
		return nil, err
	}
	return tasks, nil
}

// savetasks writes tasks into the JSON file
func saveTasks(tasks []Task) error {
	data , err := json 
}
