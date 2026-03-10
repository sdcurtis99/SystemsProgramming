// Created by Shannon Curtis on 3/3/26.
// This program reads an int from keyboard until EOF. It
// creates two child processes and connects the children and parent
// in a ring like fashion using pipes. Parent reads an int from keyboard
// and sends that value to a child via pipe. That child then sends the int
// to the other child via pipe and then return it to the parent. The parent will
// print this value and then read another int. When eof is reached
// then the parent closes its pipes and waits for the child to exit.

//          p
//        |   |
//      > c1 --> c2
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/wait.h>

int main() {

    int pipe_p_c1[2];
    if (pipe(pipe_p_c1) == -1) { perror("p_c1 pipe error"); exit(1); }
    int pipe_c1_c2[2];
    if (pipe(pipe_c1_c2) == -1) { perror("c1_c2 pipe error"); exit(1); }
    int pipe_c2_p[2];
    if (pipe(pipe_c2_p) == -1) { perror("c2_p pipe error"); exit(1); }

    pid_t pid;
    if ((pid = fork()) < 0) { return 1; }
    else if (pid == 0) {
        // --- Child 1 ---
        close(pipe_p_c1[1]);    // don't need write end of p->c1
        close(pipe_c1_c2[0]);   // don't need read end of c1->c2
        close(pipe_c2_p[0]);    // don't use pipe_c2_p at all
        close(pipe_c2_p[1]);

        int intBuf;
        while (read(pipe_p_c1[0], &intBuf, sizeof(int)) > 0) {
            intBuf *= intBuf;
            write(pipe_c1_c2[1], &intBuf, sizeof(int));
        }

        close(pipe_p_c1[0]);
        close(pipe_c1_c2[1]);
        exit(0);

    } else {
        // Parent forks Child 2
        if ((pid = fork()) < 0) { return 1; }
        else if (pid == 0) {
            // Child 2
            close(pipe_c1_c2[1]);
            close(pipe_c2_p[0]);
            close(pipe_p_c1[0]);
            close(pipe_p_c1[1]);

            int intBuf;

            while (read(pipe_c1_c2[0], &intBuf, sizeof(int)) > 0) {
                intBuf++;
                write(pipe_c2_p[1], &intBuf, sizeof(int));
            }
            close(pipe_c1_c2[0]);
            close(pipe_c2_p[1]);
            exit(0);

        } else {
            // Parent
            close(pipe_p_c1[0]);
            close(pipe_c1_c2[0]);
            close(pipe_c1_c2[1]);
            close(pipe_c2_p[1]);

            int inInt, intFromChild;
            while (scanf("%d", &inInt) == 1) {
                write(pipe_p_c1[1], &inInt, sizeof(inInt));
                read(pipe_c2_p[0], &intFromChild, sizeof(intFromChild));
                printf("%d\n", intFromChild);
            }
            close(pipe_p_c1[1]);
            close(pipe_c2_p[0]);
            wait(NULL);
            wait(NULL);
        }
    }

    return 0;
}