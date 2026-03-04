#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

/*
 * Write a C program that can take a varying number of cml that represent a known
 * unit command and their options and arguments. Your program should create a child process and
 * run the command inside the child process while main waits for the child to exit properly.
 */

int main(int argc, char* argv[]) {
    if (argc <= 1) {perror("Invalid number of arguments");}
    pid_t pid;
    if ((pid = fork()) < 0) {perror("unable to fork"); exit(1);}
    else if (pid == 0) {
        execvp(argv[1], &argv[1]);
        perror("execvp failure");
        exit(1);
    } else {
        wait(NULL);
    }
}

    // evecvp(path to search, {ls, flag, sentenial})