# Student Management System (C Language)

This is a simple command-line based Student Management System written in C.  
It allows adding, editing, searching, deleting, and sorting student records saved in a text file.

## Features

- Add a new student (with input validation)
- Search students by:
  - First name
  - Last name
  - Student number
- Delete:
  - A complete student record
  - A specific field (e.g., phone number)
- Edit any individual field
- Sort records by:
  - First name
  - Last name
  - Student number
- Load and save records from/to file

## Project Structure

```

.
├── main.c
├── student.c
├── student.h
├── students.txt      # Data file (created automatically)
├── README.md

````

## Build and Run

### Compile

```bash
gcc main.c student.c -o student-manager
````

### Run

```bash
./student-manager
```

## Data Format

Each student record is saved in a space-separated format:

```
FirstName LastName PhoneNumber HomeNumber StudentNumber Gender MilitaryCode Major Address
```

## Notes

* Maximum number of students: 1000 (can be increased in `student.h`)
* All data is stored in `students.txt`
* Data is preserved between runs

```

