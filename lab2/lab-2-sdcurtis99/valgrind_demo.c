#include <stdlib.h>
#include <stdio.h>

void my_function(char **);

int main(int argc, char *argv[]) {
    char *ptr;
    ptr = malloc(10);

    if(ptr != NULL) printf("FIRST TEST: ptr is not null\n");
    else printf("FIRST TEST: ptr is null\n");

    free(ptr);
    my_function(&ptr);

    if(ptr != NULL) printf("SECOND TEST: ptr is not null\n");
    else printf("SECOND TEST: ptr is null\n");

    //free(ptr);
}

void my_function(char **a) {
   *a = NULL;
}

/*
 * What are we allowed to change?
 * Only fnc decl/imlpment/call?
 * Alter Main's varaiables etc
 * 
 */


