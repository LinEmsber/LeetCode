/* two sum */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target)
{
        /* 1. Find the minimun and maximum numbers for map size.
         * 2. Create a two integer array for temporary variables.
         * 3. Using the length difference between max and min numbers to check.
         */
        int i;
	int min = 0;

        for( i = 0; i < numsSize; i++ ){
                if (nums[i] < min )
                        min = nums[i];
        }

	int max = target - min;
	int len_diff = max - min + 1;
	int * map = (int *) malloc( len_diff * sizeof(int) );
	int * result = (int *) malloc( 2 * sizeof(int) );

        memset(map, -1, sizeof(int) * len_diff);

        for( i = 0; i < numsSize; i++ ){

                if( ( nums[i] - min ) < len_diff ){

                        if( map[target - nums[i] - min] != -1 ){
                                result[0] = map[target - nums[i] - min];
                                result[1] = i;
                        }

                        map[nums[i] - min] = i;
                }

        }

        free(map);
        return result;
}

int main()
{
	int arr[7] = {3, 5, 9, 10, 13, 7, 8};

	int * result;

	result = twoSum(arr, 7, 17);

	printf( "twoSum(arr, 7, 17): %d, %d\n", result[0], result[1] );

	free(result);
}
