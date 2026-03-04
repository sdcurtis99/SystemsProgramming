//
// Created by Shannon Curtis on 3/3/26.
//
// This program reads an int from keyboard until EOF. It
// creates two child processes and connects the children and parent
// in a ring like fashion using pipes. Parent reads an int from keyboard
// and sends that value to a child via pipe. That child then sends the int
// to the other child via pipe and then return it to the parent. The parent will
// print this value and then read another int. When eof is reached
// then the parent closes its pipes and waits for the child to exit.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/wait.h>

int main() {

    int inInt;
    if (scanf("%d", &inInt) < 1) {return 1;}

    pid_t pid = fork();
    if (pid < 0) { return 1;}
    else if (pid == 0) {
        // child
    } else {
        //parent
        pid = fork();
    }





}