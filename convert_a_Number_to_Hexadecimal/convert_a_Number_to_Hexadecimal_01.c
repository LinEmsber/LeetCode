#include <stdio.h>
#include <stdlib.h>

char * toHex(int num)
{
	if(num == 0)
		return "0";

	int i = 0;
	int tmp;
	unsigned int * unum = (unsigned int *)&num;

	/* Include one byte for null byte and set it. */
	char * res = (char *) malloc(8 + 1);
	res[8] = 0;

	/* The given number is guaranteed to fit within the range of a 32-bit signed integer.
	 * 1. We copy the last significant 4 bits of the integer.
	 * 2. Convert this 4 bits into hexadecimal and store it into the right side of the char array.
	 * 3. The given number is right shifted 4 bits.
	 */
	while( *unum ){
		tmp = *unum & 0x0000000f;
		*(res + 7 - i) = tmp + ( (tmp > 9) ? ('a'-10) : '0' );
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
