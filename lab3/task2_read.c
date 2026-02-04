/*
 * Program opens a file at (/usr/lib/locale/locale-archive)
 * Read its conetns of that file using the read system call
 * Write the code in a manner that allows you to easily change the number of bytes read
 * use define for the array size and the argument to read
 *
 * The program shoudl read the entire file's contents.
 * Run it with sizes:
 * 		1, 2, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192
 * Record the running time with the time program on the command line (unix)
 * time ./a.out
 *
 * Plot the results and infer an char about the system
 *
 *
 *
 */
#define BUFFER_SIZE 8192
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {

	int fd;
	char buffer[BUFFER_SIZE];
	ssize_t bytesRead;
	
	fd = open("/usr/lib/locale/locale-archive", O_RDONLY);
	if (fd == -1) {return 1;}

	// Since we aren't printing anything we do not need to leave room for the '\0' therefore use BUFFER_SIZE vs BUFFER_SIZE - 1
	while ( (bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0) {
		if (bytesRead == -1) {
			perror("Failed to read from the file");
			close(fd);
			return 1;
		}
	}	

	return 0;
}
