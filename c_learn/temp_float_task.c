#include <stdio.h>

/* print Celsius-Fahrenheit table */
int main() {
	float fahr, celsius;
	float lower, upper, step;

	lower = -50.0;	/* lower limit of temperature table */
	upper = 150.0;	/* upper limit */
	step = 12.0;	/* step size */

	celsius = lower;
	printf("C to F temperature converter\n");

	while (celsius <= upper) {
		fahr = (celsius * (9.0/5.0)) + 32.0;
		printf("%6.1f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
