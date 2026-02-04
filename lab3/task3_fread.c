/*
 * Copy your program from above and modify it to use the fread library function in place of
 *  the read system call and fopen instead of open
 */
#define BUFFER_SIZE 8192
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {

	FILE* fp = NULL;
	char buffer[BUFFER_SIZE];
	size_t count;
	
	fp = fopen("/usr/lib/locale/locale-archive", "rb");
	if (!fp) {return 1;}

	// Since we aren't printing anything we do not need to leave room for the '\0' therefore use BUFFER_SIZE vs BUFFER_SIZE - 1
	// What are we assuming the binary data is representing
	while ( (count = fread(&buffer, sizeof(char), BUFFER_SIZE, fp)) > 0) {
	
	}	
	if (fp) {fclose(fp);}
	return 0;
}
