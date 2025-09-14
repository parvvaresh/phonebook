#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 1000

struct Student {
    char fname[50];
    char lname[50];
    char hnum[50];
    char pnum[50];
    char gender[50];
    char mil_num[100];
    char stu_num[50];
    char address[100];
    char major[50];
};

// Core functionalities
void add_student(struct Student students[], int *count);
void search_by_fname(struct Student students[], int count);
void search_by_lname(struct Student students[], int count);
void search_by_stu_num(struct Student students[], int count);
void delete_by_lname(struct Student students[], int *count);
void delete_field(struct Student students[], int count);
void edit_field(struct Student students[], int count);

// Sorting
void sort_by_fname(struct Student students[], int count);
void sort_by_lname(struct Student students[], int count);
void sort_by_stu_num(struct Student students[], int count);

// File I/O
int load_students(const char *filename, struct Student students[]);
void save_students(const char *filename, struct Student students[], int count);

// Validation
int is_valid_name(const char *str);
int is_valid_phone(const char *str);
int is_valid_home(const char *str);
int is_valid_gender(const char *str);
int is_valid_stu_num(const char *str);
int is_valid_military(const char *str);

#endif
