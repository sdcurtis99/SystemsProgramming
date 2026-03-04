#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// strcpy copies the string pointed to by src and its null byte
// to the buffer dest, no check for overflow!qq
char* xstrcpy(char* dest, char* src) {
    if (src == NULL || dest == NULL) {return NULL;}
    size_t i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}


// compares s1 and s2 and returns an int
// less than, equal to, or less tham zero
// if s1 is less than, matches, or greater than s2
int xstrcmp(char* s1, char* s2) {
    if (s1 == NULL || s2 == NULL) {exit(1);}
    size_t i = 0;
    while(s1[i] != '\0') {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
        i++;
    }
    return s1[i] - s2[i];
}


int main() {
    return 0;
}