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
	int i;
	int tmp;
	int count = 0;

	for (i = 0; i < 32; i++){
		tmp = n >> i;
		if ( (tmp & 0x01) == 0x01 ){
			count++;
		}
	}

	return count;
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
