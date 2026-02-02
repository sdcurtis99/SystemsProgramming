/*
 * Write the unqie utiltiy
 * It echoes to stdout its input but will only print a single instance of consequtive mathcing lines.
 *
 * Write a program with main() that takes a single cml argument specifying the file name. Read in the
 * contents of file or from stdin if not specfied and print only consequite unqiue lines to stdout.
 *
 * Use a single helper function to implment this behavior.
 *
 * Do not use any dynamic memory.
 *
 *
 */
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define MAX_LENGTH 8192


void uniq(int argc, FILE* fp) {
	char* buffer = NULL;
	size_t bufferSize = 0;
	ssize_t bytesRead = 0;
	int first = 1;
	char prevLine[MAX_LENGTH];
	while ( (argc == 2 && fp != NULL) ? ((bytesRead = getline(&buffer, &bufferSize, fp)) != -1) : ((bytesRead = getline(&buffer, &bufferSize, stdin)) != -1)) {

		if (first) {
			printf("%s", buffer);
			first = 0;
		}
		else if ((strcmp(prevLine, buffer)) != 0) {
			printf("%s", buffer);
		}
		// <= to include the string terminator '\0'
		for(ssize_t i  = 0; i <= bytesRead; i++) {
			prevLine[i] = buffer[i];
		}

	}
	free(buffer);
	return;
}

int main(int argc, char* argv[]) {
	if (argc > 2) {
		printf("Invalid number of cml arguments used in executable call");
		return -1;
	}
	FILE* fp = NULL;
	char* fileName = NULL;
	if (argc == 2) {
		fileName = argv[1];
		fp = fopen(fileName, "r");
		if(!fp) {
			printf("File could not be opened");	
			return -1;
		}
	}
	uniq(argc, fp); 
	return 1;
}
//
//
