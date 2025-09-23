# Task Manager

A simple CLI-based task manager written in **Go**.
Stores tasks in a local **JSON file**.

---

## Features

* Add tasks with **title**, **deadline**, and **category**
* List all tasks with status (done / not done)
* Mark tasks as done
* Delete tasks

---

## Installation

```bash
git clone https://github.com/yourusername/taskmanager.git
cd taskmanager
go build -o taskmanager main.go
```

---

## Usage

### Add a task

```bash
./taskmanager add "Learn Go" "2025-09-25" "Programming"
```

### List tasks

```bash
./taskmanager list
```

### Mark task as done

```bash
./taskmanager done 1
```

### Delete task

```bash
./taskmanager delete 1
```

---

## Run with Docker

```bash
docker build -t taskmanager .
docker run --rm taskmanager
```

---

## Data Storage

Tasks are stored in a local file:

```
tasks.json
```

