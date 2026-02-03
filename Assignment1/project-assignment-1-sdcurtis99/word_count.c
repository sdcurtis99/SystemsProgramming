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

void  wcResults(int resArr[], FILE* fp)  {
	int ch;
	int inWord = 0;
	int chars = 0;
	int lines = 0;
	int words = 0;

	while(((fp != NULL) ? ((ch = fgetc(fp)) != EOF) : ((ch = fgetc(stdin)) != EOF))) {
		if (ch == ' ' || ch == '\n' || ch == '\t') {
			inWord = 0;	
		}
		else if (!inWord) {
			inWord = 1;
			words++;
		}	
		chars++;
		if (ch == '\n') {lines++;}
	}
	resArr[0] = lines;
	resArr[1] = words;
	resArr[2] = chars;	
	return;
}

int main(int argc, char* argv[])  {
	
	if (argc > 2) {
		printf("Invalid number of cml arguments used in executable call");	
		return -1;
	}
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
	int resArr[MAX_LENGTH];
	wcResults(resArr, fp);
	fp ? printf("\t%d\t%d\t%d %s\n", resArr[0], resArr[1], resArr[2], fileName) : printf("\t%d\t%d\t%d\n", resArr[0], resArr[1], resArr[2]);
	return 1;
}



