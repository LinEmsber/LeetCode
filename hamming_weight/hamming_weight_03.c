/* count number of 1 bits */

#include <stdio.h>

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
        // 0b11000011111010110
        int b = 100310;
        // 0b1100001101111011
        int c = 50043;


        printf("hamming_weight(a): %d\n", hamming_weight(a) );
        printf("hamming_weight(b): %d\n", hamming_weight(b) );
        printf("hamming_weight(c): %d\n", hamming_weight(c) );


        return 0;
}
