#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {

    if (argc != 2) {return 0;}
    //endptr points to the first char not converted
    char* endptr;
    long N = strtol(argv[1], &endptr, 10);
    //printf("%ld", N);
    //fflush(stdout);
    pid_t pid;
    if ((pid = fork()) < 0)  {
        printf("Unable to fork child processes");
    }
    else if (pid == 0) {
        // Child
        for (long i = 1; i <= N; i += 2) {
            printf("%d\n", (int) i);
        } exit(0);
    } else {
        for (long i = 2; i <= N; i += 2) {
            printf("\t%d\n", (int) i);
        }
        wait(NULL);
    }
    return 0;
}

