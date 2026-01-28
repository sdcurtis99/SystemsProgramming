// Take in two command line arugments, one representing the number of times
// To print a string and the second being the string to be printed
// ** The String Should Not contain the New Line escape sequence
// 
// Validate the number of cml arguments passed, ensure the first arg
// is not negative
//
// Use the strtol() function to convert the string to an int as needed
//
//

#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[]) {

	 //Ensure that the proper amn of cml are passed on executable call
	 if (argc != 3) {
		printf("Incorrect number of cml arguments.\n");
		return 0;
	 }

	char* str = argv[1];
	char* endptr;
	long numP = strtol(str, &endptr, 10);

	//Ensure that the converstion from string to long was succesfull
	if (*endptr != '\0') {
		printf("Conversion to long was unsuccessful.\n");
		return 0;
	}

	// Ensure that the integer passed thru the cml is a postive number, representing number of occures to print to screen
	if (numP < 0) {
		printf("First cml needs to be a non-negative integer.\n");
		return 0;
	 }

	// Print the string passed by the user, numP times
	for (int i = 0; i < numP; i++) {
		printf("%s\n", argv[2]);
	}

	return 0;} 
