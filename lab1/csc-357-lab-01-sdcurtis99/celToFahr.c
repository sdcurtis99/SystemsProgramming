#include <stdio.h>


double convertCelToFahr(double cel) {
        return ((cel * 1.8) + 32);
}

int main() {

	double celsius;
	printf("Enter a temperature to be converted into fahrenheit: \n");
	scanf("%lf", &celsius);

	double fahrenheit = convertCelToFahr(celsius);

	if (fahrenheit >= 100) { printf("Heat Wave\n"); }
	else if (fahrenheit >= 80) { printf("Hot\n"); }
	else if (fahrenheit  >= 41) { printf("Norma\nl"); }
	else if (fahrenheit >= 10) { printf("Cold\n"); }
	// else block 

}
