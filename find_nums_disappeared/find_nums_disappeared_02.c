#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
	int i;
	int index = 0;
	int *tmp_array = (int *)malloc(sizeof(int) * (numsSize+1));
	int *return_array = (int *)malloc(sizeof(int) * numsSize);

	for (i = 1; i <= numsSize; i++) {
		tmp_array[i] = i;
	}

	for (i = 0; i < numsSize; i++) {
		tmp_array[nums[i]] = 0;
	}
        
	for (i = 1; i <= numsSize; i++) {
		if (tmp_array[i] != 0) {
			return_array[index++] = i;
		}
	}

	*returnSize = index;
	return return_array;
}


int main()
{
	int i = 0;
	int *ret_arr;
	int ret_size = 0;
	int arr[8] = {4,3,2,7,8,2,3,1};

	ret_arr = findDisappearedNumbers(arr, sizeof(arr)/sizeof(int), &ret_size);

	printf("ret_size: %d\n", ret_size);

	for (i = 0; i < ret_size; i++){
		printf("ret_arr[%d]: %d\n", i, ret_arr[i]);
	}

	return 0;
}
