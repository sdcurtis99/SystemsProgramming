#include <stdlib.h>

void f(void) {
	int* x = malloc(10 * sizeof(int));
	x[10] = 0; //heap block overrun and memoery leak since x not freed
}

int main(void) {
	f();
	return 0;
}


	
