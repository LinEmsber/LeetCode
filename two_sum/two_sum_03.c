/* two sum */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * twoSum(int * nums, int numsSize, int target, int* returnSize)
{
	int i, j;
	int* result = (int*) malloc(sizeof(int) * 2);

	for ( i = 0; i < numsSize; i++ ) {
		int value_diff = target - nums[i];

		for ( j = i; j < numsSize; j++ ) {
			if ( i != j && nums[j] == value_diff ) {
				result[0] = i;
				result[1] = j;
				*returnSize = 2;
				break;
			}
		}

	}
	return result;
}

int main()
{
	int arr_1[7] = {3, 5, 9, 10, 13, 7, 8};
	int arr_2[4] = {2, 7, 11, 15};
	int arr_3[7] = {3, 5, 9, 10, 13, 7, 8};

	int * result;
	int return_Size;

	result = twoSum(arr_1, 7, 17, &return_Size);
	printf( "twoSum(arr_1, 7, 17): %d, %d\n", result[0], result[1] );

	result = twoSum(arr_2, 4, 9, &return_Size);
	printf( "twoSum(arr_2, 4, 9): %d, %d\n", result[0], result[1] );

	result = twoSum(arr_3, 7, 11, &return_Size);
	printf( "twoSum(arr_3, 7, 11): %d, %d\n", result[0], result[1] );

	free(result);
}
