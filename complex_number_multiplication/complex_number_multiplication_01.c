#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char * complexNumberMultiply(char * complex_1, char * complex_2)
{
	int i, len;
	char * c1 = strdup(complex_1);
	char * c2 = strdup(complex_2);

	int complex_multiply_r, complex_multiply_i;
	int complex_1_r, complex_2_r, complex_1_i, complex_2_i;
	char * ans = (char*) malloc(8);

	/* Parse the first complex number. */
	len = strlen(c1);
	for(i = 0; i < len; ++i) {
		if(c1[i] == '+'){
			c1[i] = ' ';
			/* If we add a break, the message,"Internal error", showed on Leetcode compiler. */
			// break;
		}
	}
	c1[len-1] = 0;
	sscanf(c1, "%d %d", &complex_1_r, &complex_1_i);

	/* Parse the second complex number. */
	len = strlen(c2);
	for(i = 0; i < len; ++i) {
		if(c2[i] == '+'){
			c2[i] = ' ';
			/* If we add a break, the message,"Internal error", showed on Leetcode compiler. */
			// break;
		}
	}
	c2[len-1] = 0;
	sscanf(c2, "%d %d", &complex_2_r, &complex_2_i);

	complex_multiply_r = complex_1_r * complex_2_r - complex_1_i * complex_2_i;
	complex_multiply_i = complex_1_r * complex_2_i + complex_2_r * complex_1_i;

	sprintf(ans, "%d+%di", complex_multiply_r, complex_multiply_i);
	return ans;
}


int main()
{
	char * complex_1 = "100-100i";
	char * complex_2 = "100-100i";
	char * result;

	result = complexNumberMultiply(complex_1, complex_2);

	printf("The result of the multiply of complex number: %s\n", result);
	printf("The size of the multiply of complex number: %zu\n", sizeof(result));

	return 0;
}
