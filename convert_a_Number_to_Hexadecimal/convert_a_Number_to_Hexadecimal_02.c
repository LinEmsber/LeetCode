#include <stdio.h>
#include <stdlib.h>

const char hex_number_string[] = "0123456789abcdef";
#define DEC_TO_HEX(x) hex_number_string[((x) & 0x0f)]

char * toHex(int num)
{
	if (num == 0)
		return "0";

	int i = 0;
	unsigned int *unum = (unsigned int *) &num;

	/* Include one byte for null byte and set it. */
	char * res = (char *) malloc(8 + 1);
	res[8] = 0;

	while( *unum != 0 ){

		*(res + 7 - i) = DEC_TO_HEX(*unum);
		*unum = *unum >> 4;
		i++;
	}

	/* We only need to return the most left position of the char array which is stored number. */
	return res + 7 - i + 1;
}

int main()
{
	printf("toHex(100): %s\n", toHex(100));

	return 0;
}
