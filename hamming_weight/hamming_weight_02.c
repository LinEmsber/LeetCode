/* hamming weight */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* Write a function that takes an unsigned integer and returns the number of ’1' bits, it 
 * also known as the Hamming weight).
 *
 * For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011,
 * so the function should return 3.
 */

int hamming_weight(uint32_t n)
{
	if (n < 1)
		return  0;

	/* If n is 1, return 1.
	 * n % 2, represent the least significant bit is 1 or not.
	 * n >> 1, shift right 1 bit.
	 */
	return ( n == 1 ? 1 : ( (n % 2) + hamming_weight(n >> 1) ) );
}


int main()
{
        // 0b1100100
        int a = 100;
        // 0b111110100
        int b = 500;
        // 0b1101010000110001
        int c = 54321;

        printf("hamming_weight(a): %d\n", hamming_weight(a) );
        printf("hamming_weight(b): %d\n", hamming_weight(b) );
        printf("hamming_weight(c): %d\n", hamming_weight(c) );

        return 0;
}
