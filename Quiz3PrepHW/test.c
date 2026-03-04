#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {return 1;}

    int fd1 = open(argv[1], O_RDONLY);
    if (fd1 < 0) {perror("Failed to open file1"); return 1;}

    int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 < 0) {perror("Failed to open file2"); close(fd1); return 1;}

    if ((dup2(fd2, STDOUT_FILENO)) < 0) {perror("Dup failed"); close(fd1); close(fd2); return 1;}
    close(fd2);

    char buffer[100];
    ssize_t bytes_read;
    while ((bytes_read = read(fd1, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }
    if (bytes_read < 0) {perror("Read failure"); close(fd1); return 1;}

    close(fd1);
    return 0;
}