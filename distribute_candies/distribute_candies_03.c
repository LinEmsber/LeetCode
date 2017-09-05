#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 1. Calculate the half size, because it is the maximum of sister can obtain.
 * 2. Create a char hash table to record the uncounted numbers in bits, and add the count.
 * 3. If the count reaches the half size, that is the maximum, and we can just return it.
 */
int distributeCandies(int * candies, int candiesSize)
{
        int i;
        /* 25000 * 8 = 200000 */
        char hash[25001] = {0}, bit;
        int count = 0, number_index, hash_index, bit_index;

        for ( i = 0; i < candiesSize; i++ ) {

                number_index = candies[i] + 100000;
                hash_index = number_index / 8;
                bit_index = number_index % 8;
                bit = ( hash[hash_index] >> bit_index ) & 1;

                if (bit == 0) {
                        count++;
                        if (count == candiesSize / 2)
                                return count;
                        hash[hash_index] += 1 << bit_index;
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
