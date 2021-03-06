#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * nextGreaterElement(int * findNums, int findNumsSize, int * nums, int numsSize, int * returnSize)
{
	*returnSize = findNumsSize;

	if(findNums == NULL || findNumsSize == 0 || nums == NULL || numsSize == 0) {
		return NULL;
	}

	/* 1. Find the max element, and create a array to store the result,
	 * 2. Create a hash table to save the corresponding result number of each element of the array, findNumsSize.
	 * 3. Start to compare each the numbers of two arrays from the first element. If find the greater number,
	 * then break from the inner loop. And record the result into the hash table.
	 * 4. Convert the hash table to the result of array.
	 */
	 int i, j;
	 int max;
	 int * return_array = NULL;
	 int * nums_hash = NULL;

	 /* find the max element in the nums */
	 max = 0;
	 for(i = 0; i < numsSize; i++) {
		 if(max < nums[i]) {
			 max = nums[i];
		 }
	 }

	return_array = (int *) malloc( findNumsSize * sizeof(int) );
	if(return_array == NULL) {
                return NULL;
	}
	memset(return_array, 0, findNumsSize * sizeof(int) );

	/* Because the index of the array is zero based, we allocate one more element.
	 * It is convenient for numbers to be stored into the hash table.
	 */
	nums_hash = (int *) malloc( (max + 1) * sizeof(int) );
	if(nums_hash == NULL) {
                return NULL;
	}
	memset(nums_hash, -1, (max + 1) * sizeof(int) );

	/* Compare all elements of the array, findNumsSize, and store the result into hash. */
	for(i = 0; i < numsSize - 1; i++) {

		for(j = i + 1; j < numsSize; j++) {
			if(nums[j] > nums[i]) {
				nums_hash[nums[i]] = nums[j];
				break;
			}
		}
	}

	/* The last element. */
	nums_hash[nums[numsSize-1]] = -1;

	for(i = 0; i < findNumsSize; i++) {
		return_array[i] = nums_hash[findNums[i]];
	}

	return return_array;
}

int main()
{
        int i;
        int num_1[8] = {4, 15, 2, 3, 9, 5, 11, 10};
        int num_2[11] = {1, 3, 4, 2, 7, 13, 9, 16, 8, 12, 8};

        int * return_num;
        int return_size;

        return_num = nextGreaterElement(num_1, 8, num_2, 11, &return_size);

        for (i = 0; i < return_size; i++)
                printf("%d ", return_num[i]);
        printf("\n");

        return 0;
}
