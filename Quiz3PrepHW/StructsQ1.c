#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static Node *head;

typedef struct Student {
    char name[50];
    int ID;
    char major[10];
    struct Student *next;
} Student;


// Write a function which will write the content of a student linked list to a binary file.
// You should open the file in the function and use fwrite.
void write_to_file(Student *head) {
    FILE* fp = fopen("StudentData.txt", "wb");
    if (!fp) {perror("fopen failed"); exit(1);}
    while (head != NULL) {
        fwrite(head->name, sizeof(head.name), 1, fp);
        fwrite(&head->ID, sizeof(head->ID), 1, fp);
        fwrite(head->major, sizeof(head.major), 1, fp);
        head = head->next;
    }
    fclose(fp);
}

// Write a function that will read a binary file that contains student data
// within a student structure and displays the data on standard output
void display_student_data(FILE *fp) {
    Student temp;
    while (fread(&temp, sizeof(temp.name), 1, fp) > 0) {
        if (fread(&temp.ID, sizeof(temp.ID), 1, fp) == 0) {printf("Error reading ID\n"); exit(1);}
        if (fread(&temp.major, sizeof(temp.major), 1 , fp) == 0) {printf("Error reading ID\n"); exit(1);}
        printf("Student Information\nName: %s\n", temp.name);
        printf("Id: %d\n", temp.ID);
        printf("Major: %s\n\n", temp.major);
    }
}


// Write a function that takes an argument to the head of a linked list and deletes the entire list.
void delete_student_list(Student *head) {
    while(head != NULL) {
        Student* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Student* head = NULL;
    Student* tail = NULL;
    Student* s1 = (Student*) malloc(sizeof(Student));
    if (!s1) {perror("malloc failed"); exit(1);}
    strcpy(s1->name, "patrick");
    s1->ID = 123;
    strcpy(s1->major, "pineapple");
    head = s1;
    tail = s1;
    s1->next = NULL;


    return 0;
}