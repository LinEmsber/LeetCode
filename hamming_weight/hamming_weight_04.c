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

int hamming_weight( int a)
{
        // count bits set in this (32-bit value)
        unsigned int v = a;
        // store the total here
        unsigned int c;

        // Magic Binary Numbers
        static const int S[] = {1, 2, 4, 8, 16};
        static const int B[] = {0x55555555, 0x33333333, 0x0F0F0F0F, 0x00FF00FF, 0x0000FFFF};

        c = v - ((v >> 1) & B[0]);
        c = ((c >> S[1]) & B[1]) + (c & B[1]);
        c = ((c >> S[2]) + c) & B[2];
        c = ((c >> S[3]) + c) & B[3];
        c = ((c >> S[4]) + c) & B[4];

        return c;
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
