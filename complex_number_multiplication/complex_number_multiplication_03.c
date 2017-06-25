#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct complexNumber{
	int complex_1;
	int complex_2;
};

struct complexNumber parse_complex_number(char * n)
{
	int i = 0;
	for(; i < strlen(n); ++i){
		if(n[i] == '+'){
			break;
		}
	}

	struct complexNumber result = {atoi(&n[0]), atoi(&n[i+1])};
	return result;
}

char * complexNumberMultiply(char * complex_1, char * complex_2)
{
	struct complexNumber c1 = parse_complex_number(complex_1);
	struct complexNumber c2 = parse_complex_number(complex_2);

	char* result = (char*)calloc(8, sizeof(char));
	memset(result, '\0', 8);

	sprintf(result, "%d+%di", (c1.complex_1 * c2.complex_1 - c1.complex_2 * c2.complex_2), (c1.complex_1 * c2.complex_2 + c1.complex_2 * c2.complex_1));

	return result;
}

int main()
{
	char * complex_1 = "100+-0i";
	char * complex_2 = "100+-100i";
	char * result;

	result = complexNumberMultiply(complex_1, complex_2);

	printf("The result of the multiply of complex number: %s\n", result);
	printf("The size of the multiply of complex number: %zu\n", sizeof(result));

	return 0;
}
