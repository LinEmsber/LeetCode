#include <stdio.h>

// print integer in binary for 8-bits
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c\n"

// convert binary number to char
#define BYTE_TO_BINARY(byte)  		\
	(byte & 0x80 ? '1' : '0'), 	\
	(byte & 0x40 ? '1' : '0'), 	\
	(byte & 0x20 ? '1' : '0'), 	\
	(byte & 0x10 ? '1' : '0'), 	\
	(byte & 0x08 ? '1' : '0'), 	\
	(byte & 0x04 ? '1' : '0'), 	\
	(byte & 0x02 ? '1' : '0'), 	\
	(byte & 0x01 ? '1' : '0')



int findComplement(int num)
{
	unsigned mask = ~0;
	while (num & mask)
		mask <<= 1;
	return ~mask & ~num;
}

int main()
{
	int a = 5;
	int a_complement;

	printf("a: %d, a: "BYTE_TO_BINARY_PATTERN, a, BYTE_TO_BINARY(a));

	a_complement = findComplement(a);

	printf("a_complement: %d, a_complement: "BYTE_TO_BINARY_PATTERN, a_complement, BYTE_TO_BINARY(a_complement));

	return 0;
}
