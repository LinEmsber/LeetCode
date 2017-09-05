#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 1. Calculate the half size, because it is the maximum of sister can obtain.
 * 2. Create a char hash table to record the uncounted numbers in bits, and add the count.
 * 3. If the count reaches the half size, that is the maximum, and we can just return it.
 */

#define TEST_BIT(A,k)    ( A[(k / 8)] & (1 << (k % 8)) )
#define SET_BIT(A,k)     ( A[(k / 8)] |= (1 << (k % 8)) ) ? 1 : 0

int distributeCandies(int * candies, int candiesSize)
{
        int i;
        /* 25000 * 8 = 200000 */
        char hash[25001] = {0}, bit;
        int half_size = candiesSize / 2;
        unsigned int count = 0, number_index;

        for ( i = 0; i < candiesSize; i++ ) {

                // Turn in positive number.
                number_index = candies[i] + 100000;

                bit = TEST_BIT(hash, number_index);

                if (bit == 0) {
                        count++;
                        if (count == half_size)
                                return count;
                        SET_BIT(hash, number_index);
                }

        }
        return count;
}

int main()
{
	int candies[16] = {1, 1, 2, 2, 3, 3, 5, 8, 4, 3, 5, 8, 10, 3, 6, 10};
	int candies_size = sizeof(candies) / sizeof(int);

	printf("Distribute Candies: %d\n", distributeCandies(candies, candies_size));

	return 0;
}
