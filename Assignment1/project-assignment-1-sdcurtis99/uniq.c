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
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * uniq takes a file pointer and prints all unqiue lines which are nonconseuqtive from wither a file or stdin. 
 * the function uses two buffers so that consequitve lines can be compared using strcmp
 */
void uniq(FILE* fp) {

	// flag for first line
	int first = 1;

	// buffers used to store the current and previous lines
	char* curBuffer = NULL;
	char* prevBuffer = NULL;
	char* tempBuffer;

	// sizes associated with the getline buffers above
	size_t tBufferSize;
	size_t pBufferSize = 0;
	size_t cBufferSize = 0;

	// flasg to track whether the buffers have been allocated
	int pBufferNull = 1;
	int cBufferNull = 1;

	// If the fp is not null then use the fileName passed in the cml otherwise read in from stdin
	// Getline is used once here so that we can use two different buffers one to store prev and curr line for use in strcmp
	
	fp != NULL ? (getline(&prevBuffer, &pBufferSize, fp) != -1) : (getline(&prevBuffer, &pBufferSize, stdin) != -1);
	pBufferNull = 0;

	// If the fp is not null then use the fileName passed in the cml otherwise read in from stdin
	
	while ( (fp != NULL) ? (getline(&curBuffer, &cBufferSize, fp) != -1) : (getline(&curBuffer, &cBufferSize, stdin) != -1) ) {

		// The first line must always be unqiue so handle this case and set the first flag to false.
		// the currBuffer has been allocated, flip the flag
		cBufferNull = 0;
		if (first) {
			printf("%s", prevBuffer);
			first = 0;
		}

		// For all other lines in the file.
		// Print only the current line if it is different from the previous line
		else if ((strcmp(prevBuffer, curBuffer)) != 0) {
			printf("%s", curBuffer);
		}
		 

		// Swap the buffers so the current line become the previosu for next iteration
		tempBuffer = curBuffer;
		curBuffer = prevBuffer;
		prevBuffer = tempBuffer;

		// Swap the buffer sizes so they are associated with the proper buffer in getline
		tBufferSize = cBufferSize;
		cBufferSize = pBufferSize;
		pBufferSize = tBufferSize;
		
	}
	// Free the dynamic mem allocated in getline() only if they were allocaterd
	if (!cBufferNull) {
		free(curBuffer);
	}
	if(!pBufferNull) {
		free(prevBuffer);
	}
	return;
}

// Handles the cmnl arguments and file opening if provided, otherwise input will be used from stdin
//
int main(int argc, char* argv[]) {

	// ensure no more than a single cml arugment was provided
	if (argc > 2) {
		printf("Invalid number of cml arguments used in executable call");
		return -1;
	}

	// If a fileName is provided attempt to open it
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
	// Pass the file pointer for uniq to use
	uniq(fp); 
	return 0;
}
