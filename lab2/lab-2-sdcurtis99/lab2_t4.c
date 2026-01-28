#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {

	if (argc <= 1) {return 1;}	
	
	for(int i = 1; i < argc; i++) {
		if(argv[i][0] == '-') {
			printf("%s\n\n", argv[i]);	
		}
	}

	return 0;
}
