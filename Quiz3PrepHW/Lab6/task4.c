#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#define N "47"



// task
// take 2 cml args:
// name of another program, the name of the file which may not exist yet
// Program will use exec to run the specified program and redirect the stdout to
// the file which may ore may not exist yet
// This setup is done such that the exec'd program will write its output to the file


int main(int argc, char* argv[]) {
    if (argc != 3) {return 0;}
    int fd = open(argv[2], O_WRONLY | O_CREAT, 0644);
    if (fd < 0) {perror("Error opening/creating file"); exit(1);}
    pid_t pid;
    if ((pid = fork()) < 0) {perror("failed to fork"); exit(1);}
    else if (pid == 0) {
        if (dup2(fd, STDOUT_FILENO) < 0) { perror("dup2 failed"); exit(1); }
        close(fd);
        execlp(argv[1], argv[1], N, NULL);
        perror("execlp failed");
        exit(1);
    } else {
        close(fd);
        wait(NULL);

    }
}