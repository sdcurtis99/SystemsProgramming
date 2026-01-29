/*
 * Read in from a file or from stdin and count the number of characters, words, and lines in the file or string.
 *
 * It should take a single optional cml argument specfiying a file name. It must read the content of the files or from stdin and print .... . Use a single helper function to implment the function required.
 *
 * Note the program should not use any form od dyanmic memmoery allocation. It should read a SINGLE CHARACTER at a time. Multiple white spaces should be treated as a single ws delimiter.
 *
 */



/*
 *	ToDo:
 *		Implment wc logic into a function
 *		Check logic is correct
 *		Ensure logic covers all possible edges cases
 *		Add validation for errors etc
 *		Try and make code as safe as possible
 */

#include <stdio.h>

int main(int argc, char* argv[])  {
	
	// if proper amount of cml, ie user might have passed a proper file name
	if (argc == 2) {

		FILE* fp = fopen(argv[1], "r");

		if (fp == NULL) {
			printf("Error opening file given in cml");
			return -1;
		}

		int inWord = 0;
		int chars = 0;
		int lines = 0;
		int words = 0;
		while ( (ch = fgetc(fp)) != EOF ) {
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

	// logic for stdin since no file name is provided
	else if (argc = 1) {
		char ch;
		int inWord = 0;
		int chars = 		
		while (scanf("%c", &ch) == 1) {
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
	}
	// logic for inproper and unhandled number of cml
	else {
		printf("Invalid number of command line arguments");
		return -1;
	}
	
	return 1;
}
