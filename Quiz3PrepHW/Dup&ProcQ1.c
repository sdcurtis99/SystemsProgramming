#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

/*
 * Write a program which takes 2 cml
 * It reads from the 1st a file and then
 * redirects the stdout to write content of the first file to the second file.
 * Upon completeion, the second file should contain the same contents as the first
 *
 * Account for all possible errors, file managements, string errors, and
 * properly utilize system resources.
 */

int main(int argc, char * argv[]) {
    // Validation
    if (argc != 3) {return 1;}
    int fd1 = open(argv[1], O_RDONLY);
    if (fd1 < 0) { perror("Failed to open file1"); exit(1);}
    int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0754);
    if (fd2 < 0) { perror("Failed to open file2"); exit(1);}

    // Redirect printf aka stdout to fp2
    // STDOUT_FILENO = f2
    // No need for backup since we do not need to restore
    if ((dup2(fd2, STDOUT_FILENO)) < 0) {perror("Dup failed"); exit(1);}
    close(fd2);

    char buffer[100];
    ssize_t bytes_read;
    // use bytes read so we have the null term exactly after the data we read
    while ((bytes_read = read(fd1, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }
    if (bytes_read < 0) {perror("Read failure"); exit(1);}
    close(fd1);
    return;
}