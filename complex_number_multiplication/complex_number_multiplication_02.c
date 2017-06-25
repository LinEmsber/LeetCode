#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char * complexNumberMultiply(char * complex_1, char * complex_2)
{
	int complex_1_r, complex_1_i;
	int complex_2_r, complex_2_i;
	int complex_multiply_r, complex_multiply_i;

	char * ans = malloc(8);

	sscanf(complex_1, "%d+%di", &complex_1_r, &complex_1_i);
	sscanf(complex_2, "%d+%di", &complex_2_r, &complex_2_i);

	complex_multiply_r = complex_1_r * complex_2_r - complex_1_i * complex_2_i;
	complex_multiply_i = complex_1_r * complex_2_i + complex_1_i * complex_2_r;

	sprintf(ans, "%d+%di", complex_multiply_r, complex_multiply_i);

	return ans;
}


int main()
{
	char * complex_1 = "100+-100i";
	char * complex_2 = "100+-100i";
	char * result;

	result = complexNumberMultiply(complex_1, complex_2);

	printf("The result of the multiply of complex number: %s\n", result);
	printf("The size of the multiply of complex number: %zu\n", sizeof(result));

	return 0;
}
