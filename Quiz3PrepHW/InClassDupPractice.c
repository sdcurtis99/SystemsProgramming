#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// Write a program emulating redirector operator used with cat
// Accept a text file name as a cml
// use dup and dup2 system calls to redirect the output of a printf statement.
// after redirecting the program should restore stdout and print another message using printf to write to terminal.

int main(int argc, char* argv[]) {
    // argc count check
    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    // check fd is positive
    int backup_fd = dup(STDOUT_FILENO);
    if ((dup2(fd, STDOUT_FILENO)) < 0) {exit(1);}
    // STDOUT... = fd
    // close(fd)
    // Now STDOUT goes to testdupfile.txt
    printf("This goes to the file\n");
    fflush(stdout);
    // restore stdout;
    if ((dup2(backup_fd, STDOUT_FILENO)) < 0) {exit(1);}
    //close(bakcup_fd)
    printf("This goes to the terminal\n");
    close(fd);
    close(backup_fd);
    return 0;
}