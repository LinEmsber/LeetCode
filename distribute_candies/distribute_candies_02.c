#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 1. Find the maximum and the minimum of the numbers.
 * 2. Create a fit range hash table to record uncounted numbers.
 */

int distributeCandies(int * candies, int candiesSize)
{
        int i;
        int min = INT_MAX, max = INT_MIN;

        /* Find the max and min numbers of the candies array. */
        for(i = 0; i < candiesSize; i++) {
                min = (min > candies[i]) ? candies[i] : min;
                max = (max < candies[i]) ? candies[i] : max;
        }

        int * hash = malloc(sizeof(int) * (max - min + 1));
        memset(hash, 0, sizeof(int) * (max - min + 1));
        int count = 0;

        for( i = 0; ( i < candiesSize ) && ( count < candiesSize / 2 ); i++) {

                hash[(candies[i] - min)]++;

                if (hash[(candies[i] - min)] == 1) {
                        count++;
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
