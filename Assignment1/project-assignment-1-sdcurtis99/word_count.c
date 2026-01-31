/*
 * Read in from a file or from stdin and count the number of characters, words, and lines in the file or string.
 *
 * It should take a single optional cml argument specfiying a file name. It must read the content of the files or from stdin and print .... . Use a single helper function to implment the function required.
 *
 * Note the program should not use any form od dyanmic memmoery allocation. It should read a SINGLE CHARACTER at a time. Multiple white spaces should be treated as a single ws delimiter.
 *
 */


:
/*
 *	ToDo:
 *		Implment wc logic into a function
 *		Check logic is correct
 *		Ensure logic covers all possible edges cases
 *		Add validation for errors etc
 *		Try and make code as safe as possible
 */

#include <stdio.h>
#define LENGTH 3

void  wcResults(int* array, int argc, FILE* fp) {
	char ch;
	int inWord = 0;
	int chars = 0;
	int lines = 0;
	int words = 0;
	while( ( (argc == 2 && fp != NULL) ? (ch = fgetc(fp) != EOF) : (scanf("%c", &ch) == 1) ) ) {
		if (ch = ' ') {
			inWord = 0;	
		}
		if ((ch != ' ') && inWord = 0) {
			inWord = 1;
			word++
		}	
		chars++;
		if (ch == '\n') {lines++;}
	}
	arr[0] = lines;
	arr[1] = words;
	arr[2] = chars;	
	return 0;
}

int main(int argc, char* argv[])  {
	
	if (argc > 2) {
		printf("Invalid number of cml arguments used in executable call");	
		return -1;
	}
	char* fileName = argv[1]
	int* resArr =  (int *) malloc(sizeof(int) * LENGTH);
	wcResults(resArr, argc, fp);
	printf("/t%d/t%d/t%d %s\n", resArr[0], resArr[1], resArr[2], fileName);	
	return 1;
}




