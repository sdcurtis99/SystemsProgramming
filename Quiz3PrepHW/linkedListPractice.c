

Student* add_student_to_list(Student* head, const char name[], int id, const char major[]) {
    Student *newStu = (Student*)  malloc(sizeof(Student));
    if (!newStu) {return NULL;}
    // last student will point to null and needs it data
    newStu->next = NULL;
    strcpy(newStu->name, name);
    strcpy(newStu->major, major);
    newStu->id = id;
    if (!head) {return newStu;}
    Student* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newStu;
    return head;
}