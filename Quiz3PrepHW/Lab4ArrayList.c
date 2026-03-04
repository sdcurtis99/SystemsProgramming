#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct arrayList {
    char** data;
    size_t capacity;
    size_t size;
} arrayList;

// Dynamically allocate an arraylist structure
// Track resizeable array, capacity, currentNumber,
// Init cap is up to you
arrayList* array_list_new(int cap) {
    arrayList* list = (arrayList*) malloc(sizeof(arrayList));
    if (!list) {printf("Malloc failed"); exit(1);}
    list->data = (char**) malloc(sizeof(char*) * cap);
    if (!list->data) {printf("Malloc failed"); exit(1);}
    list->size = 0;
    list->capacity = cap;
    return list;
}

// Take an arraylist and a string and add to the end of the list
// If no space resize the array
void array_list_add_to_end(arrayList* list, char* str) {
    if (list == NULL || str == NULL) {printf("invalid data passed"); exit(1);}
    if (list->size == list->capacity) {
        char** temp = realloc(list->data, sizeof(char*) * list->capacity * 2);
        if (!temp) {printf("realloc failed"); exit(1);}
        list->capacity *= 2;
        list->data = temp;
    }
    // Now has room add
    char* copy = (char*) malloc(strlen(str)+1);
    if (!copy) {exit(1);}
    strcpy(copy, str);
    list->data[list->size++] = copy;
}

void free_array_list(arrayList* list) {
    if (list == NULL) {return;}
    for (size_t i = 0; i < list->size; i++) {
        free(list->data[i]);
    }
    free(list->data);
    free(list);
    return;
}

int main() {

    return 0;
}