/* two sum */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	/* 1. Find the minimun and maximum numbers
	 * 2. Set the difference between two numbers as the size of map.
	 * 3. Traverse all of the elements and use the map to record their index.
	 */
	int i, tmp, min = 0;

	for( i = 0; i < numsSize; i++ ){
		if (nums[i] < min )
			min = nums[i];
	}

	int max = target - min;
	// The length of integers is between maximum and minimun.
	int value_diff = max - min + 1;

	int * map = malloc( value_diff * sizeof(*map) );
	int * result = malloc( 2 * sizeof(*result) );

	memset(map, -1, sizeof(int) * value_diff);

	for( i = 0; i < numsSize; i++ ){
		tmp = target - nums[i];
		if( tmp >= min && tmp <= max ){
			// The map record the index of elements.
			if( map[target - nums[i] - min] != -1 ){
				result[0] = map[target - nums[i] - min];
				result[1] = i;
				*returnSize = 2;
				break;
			} else {
				map[nums[i] - min] = i;
			}
		}
	}
	// free(map);
	return result;
}

int main()
{
	int arr_1[7] = {3, 5, 9, 10, 13, 7, 8};
	int arr_2[4] = {2, 7, 11, 15};

	int * result;
	int return_Size;

	result = twoSum(arr_1, 7, 17, &return_Size);
	printf( "twoSum(arr_1, 7, 17): %d, %d\n", result[0], result[1] );

	result = twoSum(arr_2, 4, 9, &return_Size);
	printf( "twoSum(arr_2, 4, 9): %d, %d\n", result[0], result[1] );

	free(result);
}
