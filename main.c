#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

#define FILENAME "students.txt"

int main() {
    struct Student students[MAX_STUDENTS];
    int student_count = load_students(FILENAME, students);

    int choice;
    do {
        printf("\n=== Student Management System ===\n");
        printf("1. Add student\n");
        printf("2. Search by first name\n");
        printf("3. Search by last name\n");
        printf("4. Search by student number\n");
        printf("5. Delete student by last name\n");
        printf("6. Delete student field\n");
        printf("7. Edit student field\n");
        printf("8. Sort by first name\n");
        printf("9. Sort by last name\n");
        printf("10. Sort by student number\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                add_student(students, &student_count);
                save_students(FILENAME, students, student_count);
                break;
            case 2:
                search_by_fname(students, student_count);
                break;
            case 3:
                search_by_lname(students, student_count);
                break;
            case 4:
                search_by_stu_num(students, student_count);
                break;
            case 5:
                delete_by_lname(students, &student_count);
                save_students(FILENAME, students, student_count);
                break;
            case 6:
                delete_field(students, student_count);
                save_students(FILENAME, students, student_count);
                break;
            case 7:
                edit_field(students, student_count);
                save_students(FILENAME, students, student_count);
                break;
            case 8:
                sort_by_fname(students, student_count);
                save_students(FILENAME, students, student_count);
                break;
            case 9:
                sort_by_lname(students, student_count);
                save_students(FILENAME, students, student_count);
                break;
            case 10:
                sort_by_stu_num(students, student_count);
                save_students(FILENAME, students, student_count);
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
