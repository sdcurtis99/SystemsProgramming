#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

// Write a C program which uses any of the exec system calls to display
// the current date and time by running unix date

int main() {
    pid_t pid;
    if ((pid = fork()) < 0) {perror("Forked failed");}
    else if (pid == 0) {
        execlp("date", "date", NULL);
        perror("execlp failed");
        exit(1);
    } else {
        wait(NULL);
    }
}