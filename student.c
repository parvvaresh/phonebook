#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "student.h"

// Check if string contains digits (for name fields)
int is_valid_name(const char *str) {
    for (int i = 0; str[i]; i++)
        if (isdigit(str[i])) return 0;
    return 1;
}

// Check if phone number is 11 digits and all numeric
int is_valid_phone(const char *str) {
    if (strlen(str) != 11) return 0;
    for (int i = 0; str[i]; i++)
        if (!isdigit(str[i])) return 0;
    return 1;
}

// Check if home number is 8 digits
int is_valid_home(const char *str) {
    if (strlen(str) != 8) return 0;
    for (int i = 0; str[i]; i++)
        if (!isdigit(str[i])) return 0;
    return 1;
}

// Check if student number is 7 digits
int is_valid_stu_num(const char *str) {
    if (strlen(str) != 7) return 0;
    for (int i = 0; str[i]; i++)
        if (!isdigit(str[i])) return 0;
    return 1;
}

// Check if military code is 9 digits
int is_valid_military(const char *str) {
    if (strlen(str) != 9) return 0;
    for (int i = 0; str[i]; i++)
        if (!isdigit(str[i])) return 0;
    return 1;
}

// Read from file
int load_students(const char *filename, struct Student students[]) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return 0;

    int count = 0;
    while (fscanf(fp, "%s %s %s %s %s %s %s %s %[^\n]",
                  students[count].fname, students[count].lname,
                  students[count].pnum, students[count].hnum,
                  students[count].stu_num, students[count].gender,
                  students[count].mil_num, students[count].major,
                  students[count].address) == 9) {
        count++;
    }

    fclose(fp);
    return count;
}

// Save to file
void save_students(const char *filename, struct Student students[], int count) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s %s %s %s %s %s %s %s %s\n",
                students[i].fname, students[i].lname,
                students[i].pnum, students[i].hnum,
                students[i].stu_num, students[i].gender,
                students[i].mil_num, students[i].major,
                students[i].address);
    }

    fclose(fp);
}
