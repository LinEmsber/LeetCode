#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 1. Calculate the half size, because it is the maximum of sister can obtain.
 * 2. Create a boolean hash table to record the uncounted numbers, and add the count.
 * 3. If the count reaches the half size, that is the maximum, and we can just return it.
 */
int distributeCandies(int * candies, int candiesSize)
{
        int i;
        int count = 0;
        int half_size = candiesSize / 2;
        bool * hash = malloc( sizeof(int) * 200001 );

        for ( i = 0; i < candiesSize; ++i ) {

                if ( !hash[candies[i] + 100000] ) {

                        if ( count == half_size ) {
                                return half_size;
                        }

                        count++;
                        hash[candies[i] + 100000] = true;
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
