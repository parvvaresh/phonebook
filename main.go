package main

import (
	"encoding/json"
	"fmt"
	"os"
	"strconv"
)

// Task  struct defines a single task

type Task struct {
	ID    int    `json:"id"`
	Title string `json:"title"`
	Done  bool   `json:"done"`
}

var filename = "tasks.json"

// loadtasks reads tasks fron the JSON file
func loadTasks() ([]Task, error) {
	var tasks []Task
	file, err :=  os.ReadFile(filename)
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
	data , err := json.MarshalIndent(tasks, "", "  ")
	if err != nil {
		return err
	}
	return os.WriteFile(filename, data, 0644)
}

// addTask adds a new task to rhe list
func addTask(title string) error {
	tasks, err :=  loadTasks()

	if err != nil {
		return err
	}
	newID := len(tasks) + 1
	tasks = append(tasks, Task{ID: newID,Title: title,Done: false})
	return saveTasks(tasks)
}

// listtasks prints all tasks
func listTasks() error {
	tasks, err := loadTasks()
	if err != nil {
		return err
	}
	if len(tasks) == 0 {
		fmt.Println("No tasks found!")
		return nil
	}

	for _, t := range tasks {
		status := "❌"
		if t.Done {
			status = "✅"
		}
		fmt.Println("%d. %s [%s]\n", t.ID, t.Title, status)

	}
	return nil
}

//markdone marks a task as completed
func markDone(id int) error {
	tasks, err :=  loadTasks()
	if err != nil {
		return err
	}
	for i := range tasks {
		if tasks[i].ID == id {
			tasks[i].Done = true
			break
		}
	}
	return saveTasks(tasks)
}

/// deleteTasks removes a task by ID
func deleteTask(id int) error {
	tasks, err := loadTasks()
	if err != nil {
		return err
	}

	newTasks:= []Task{}
	for _, t := range tasks {
		if t.ID != id {
			newTasks = append(newTasks, t)
		}
	}
	return saveTasks(newTasks) 
}


// main handles CLI arguments
func main() {
	if len(os.Args) < 2 {
		fmt.Println("Usage: go run main.go [add|list|done|delete] [task]")
		return
	}

	command := os.Args[1]

	switch command {
	case "add":
		if len(os.Args) < 3 {
			fmt.Println("Please provide a task title")
			return
		}
		title := os.Args[2]
		err := addTask(title)
		if err != nil {
			fmt.Println("Error:", err)
		} else {
			fmt.Println("Task added:", title)
		}

	case "list":
		err := listTasks()
		if err != nil {
			fmt.Println("Error:", err)
		}

	case "done":
		if len(os.Args) < 3 {
			fmt.Println("Please provide task ID")
			return
		}
		id, _ := strconv.Atoi(os.Args[2])
		err := markDone(id)
		if err != nil {
			fmt.Println("Error:", err)
		} else {
			fmt.Println("Task marked as done:", id)
		}

	case "delete":
		if len(os.Args) < 3 {
			fmt.Println("Please provide task ID")
			return
		}
		id, _ := strconv.Atoi(os.Args[2])
		err := deleteTask(id)
		if err != nil {
			fmt.Println("Error:", err)
		} else {
			fmt.Println("Task deleted:", id)
		}

	default:
		fmt.Println("Unknown command:", command)
	}
}
