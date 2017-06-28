#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int distributeCandies(int * candies, int candiesSize)
{
        int i;
        /* 25000 * 8 = 200000 */
        int hash[25001] = {0};
        int count = 0, number_index, bit, hash_index, bit_index;

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
