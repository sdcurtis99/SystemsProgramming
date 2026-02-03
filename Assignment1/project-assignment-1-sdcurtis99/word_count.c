/*
 * Read in from a file or from stdin and count the number of characters, words, and lines in the file or string.
 *
 * It should take a single optional cml argument specfiying a file name. It must read the content of the files or from stdin and print .... . Use a single helper function to implment the function required.
 *
 * Note the program should not use any form od dyanmic memmoery allocation. It should read a SINGLE CHARACTER at a time. Multiple white spaces should be treated as a single ws delimiter
 *	ToDo:
 *		Implment wc logic into a function
 *		Check logic is correct
 *		Ensure logic covers all possible edges cases
 *		Add validation for errors etc
 *		Try and make code as safe as possible
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 3


// Reads in characters from a file pointer and computes the
// number of lines words and characters
// fp is the file pointer
// fileName is the name of the file if provided

void  wcResults(FILE* fp, char* fileName)  {
	// ch is the current character being read
	int ch;
	// inWord is a flag indicating if we are currently in a word
	int inWord = 0;
	// The following ints store the counts we will later flush to stdout
	int chars = 0;
	int lines = 0;
	int words = 0;

	// If there is a valid file read from it or get input from stdin
	while(((fp != NULL) ? ((ch = fgetc(fp)) != EOF) : ((ch = fgetc(stdin)) != EOF))) {
		// If a whitespace is encountered we are no longer in a word, multiples are a single delimiter
		if (ch == ' ' || ch == '\n' || ch == '\t') {
			inWord = 0;	
		}
		// If not a whitespace char and we are not altready in a word a new word has begun
		else if (!inWord) {
			inWord = 1;
			words++;
		}
		// increment chars for every char read an inc lines if a new line is present
		chars++;
		if (ch == '\n') {lines++;}
	}

	// Store the results in the array
	fp ? printf("\t%d\t%d\t%d %s\n", lines, words, chars, fileName) : printf("\t%d\t%d\t%d\n", lines, words, chars);
	return;
}

int main(int argc, char* argv[])  {
	// Ensure no more cml arguments are provided than expected
	if (argc > 2) {
		//printf("Invalid number of cml arguments used in executable call");	
		return -1;
	}
	// If a file is provided attempt to open it otherwise stdin will be used once fp is null and passed to wcResults
	FILE* fp = NULL;
	char* fileName = NULL; 
	if (argc == 2) {
		fileName = argv[1];
		fp = fopen(fileName, "r");
		if (!fp) {
			printf("File could not be opened/does not exist.");
			return -1;
		}
	}
	// Compute and display the number of lines words and chars from the provided file pointer
	wcResults(fp, fileName);
	return 1;
}



