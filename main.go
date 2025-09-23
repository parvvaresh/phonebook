package main

import (
	"encoding/json"
	"fmt"
	"os"
	"strconv"
)

// Task struct defines a single task
type Task struct {
	ID       int    `json:"id"`
	Title    string `json:"title"`
	Done     bool   `json:"done"`
	Deadline string `json:"deadline"`
	Category string `json:"category"`
}

var fileName = "tasks.json"

// loadTasks reads tasks from the JSON file
func loadTasks() ([]Task, error) {
	var tasks []Task

	file, err := os.ReadFile(fileName)
	if err != nil {
		if os.IsNotExist(err) {
			return tasks, nil // if file does not exist, return empty list
		}
		return nil, err
	}

	err = json.Unmarshal(file, &tasks)
	if err != nil {
		return nil, err
	}

	return tasks, nil
}

// saveTasks writes tasks into the JSON file
func saveTasks(tasks []Task) error {
	data, err := json.MarshalIndent(tasks, "", "  ")
	if err != nil {
		return err
	}

	return os.WriteFile(fileName, data, 0644)
}

// addTask adds a new task to the list
func addTask(title, deadline, category string) error {
	tasks, err := loadTasks()
	if err != nil {
		return err
	}

	newID := len(tasks) + 1
	tasks = append(tasks, Task{
		ID:       newID,
		Title:    title,
		Done:     false,
		Deadline: deadline,
		Category: category,
	})

	return saveTasks(tasks)
}

// listTasks prints all tasks
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
		fmt.Printf("%d. %s [%s] (Deadline: %s, Category: %s)\n",
			t.ID, t.Title, status, t.Deadline, t.Category)
	}
	return nil
}

// markDone marks a task as completed
func markDone(id int) error {
	tasks, err := loadTasks()
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

// deleteTask removes a task by ID
func deleteTask(id int) error {
	tasks, err := loadTasks()
	if err != nil {
		return err
	}

	newTasks := []Task{}
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
		fmt.Println("Usage: go run main.go [add|list|done|delete] [args]")
		return
	}

	command := os.Args[1]

	switch command {
	case "add":
		if len(os.Args) < 5 {
			fmt.Println("Usage: go run main.go add <title> <deadline> <category>")
			return
		}
		title := os.Args[2]
		deadline := os.Args[3]
		category := os.Args[4]
		err := addTask(title, deadline, category)
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
