#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * nextGreaterElement(int * findNums, int findNumsSize, int * nums, int numsSize, int * returnSize)
{
	int i, j;
	int max;
	int * return_array = NULL;
	int * nums_hash = NULL;

	*returnSize = findNumsSize;

	if(findNums != NULL && findNumsSize != 0 && nums != NULL && numsSize != 0) {

		/* initalize the return_array */
		return_array = malloc((*returnSize) * sizeof(int));
		if(return_array == NULL) {
                        return NULL;
		}

		max = 0;
		for(i = 0; i < numsSize; i++) {
			if(max < nums[i]) {
				max = nums[i];
			}
		}

		nums_hash = (int *) malloc( (max + 1) * sizeof(int) );
		if(nums_hash == NULL) {
                        return NULL;
		}

		for(i = 0; i < numsSize-1; i++) {

			nums_hash[nums[i]] = -1;
			for(j = i + 1; j < numsSize; j++) {

				if(nums[j] > nums[i]) {
					nums_hash[nums[i]] = nums[j];
					break;
				}
			}
		}
		nums_hash[nums[numsSize-1]] = -1;

		/* find the next greater element */
		for(i = 0; i < findNumsSize; i++) {
			return_array[i] = nums_hash[findNums[i]];
		}
	}

	return return_array;
}

int main()
{
        int i;
        int num_1[3] = {4, 1, 2};
        int num_2[4] = {1, 3, 4, 2};

        int * return_num;
        int return_size;

        return_num = nextGreaterElement(num_1, 3, num_2, 4, &return_size);

        for (i = 0; i < return_size; i++)
                printf("%d ", return_num[i]);
        printf("\n");

        return 0;
}
