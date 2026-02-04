#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>


/*
 *
 * Write a program which accepts a cml, fileName, and prints the last two lines of the file
 * For cases where there are fewer or exactly than two lines print those lines
 *
 * Think about what your edge cases may be
 *
 * Do not use any alloc functions
 * Use getline to read lines in for file
 * Remeber to use Free
 * It may be helpful to use rewind() if needed
 * void rewind(FILE* stream)
 * 	Repositions the cursor back to the byte 0 of the file
 *
 *
 */

int main(int argc, char* argv[]) {

	// If we were passed a possible file name in execution call
	// If file not opened succesfully or inproper ammount of cml arguments terminate
	FILE* fp = NULL;
	if (argc == 2) {
		char* fileName = argv[1];
		fp = fopen(fileName, "r");
		if (!fp) {return 1;}
	} else {return 1;}
	
	// At this point we must have a valid file to read from
	char* buffer = NULL;
	size_t bufferSize = 0;
	ssize_t bytesRead = 0;
	int numLinesInFile = 0;
	while ( (bytesRead = getline(&buffer, &bufferSize, fp)) != -1) {
		numLinesInFile++;
	}
	// Do we need to reset buffer and bufferSize and free first or ca I just re use them
	free(buffer);
	buffer = NULL;
	bufferSize = 0;
	// Assume at lease one line in the file since the while loop wont run for a comepletly empty file
	int curLine = 1;
	// Reset the file pointer to the beginning of the file
	rewind(fp);
	while ( (bytesRead = getline(&buffer, &bufferSize, fp)) != -1) {
		if ( ((numLinesInFile - curLine) <= 1) && ((numLinesInFile - curLine) >= 0) ) {
			// Note the if there is not '\n' on the last line getline will not append one
			printf("%s", buffer);
		}
		curLine++;
	}
	free(buffer);
	if (fp) {fclose(fp);}
	return 0;
}

