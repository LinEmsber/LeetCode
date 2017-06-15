/* Search Insert Position */

#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target) 
{
	if(nums == NULL)
		return 0;

	int i;
	for(i = 0; i < numsSize; i++){
		if(nums[i] == target){
			return i;
		}
	}

	for(i = 0; i < numsSize; i++){
		if(target > nums[i]){
			if(i == numsSize - 1){
				return numsSize;
			}else if(target < nums[i + 1]){
				return i + 1;
			}
		}
	}

	return 0;
}

int main()
{
	int arr[20] = {2, 5, 9, 10, 11, 13, 15, 17, 20, 23, 
			25, 28, 31, 32, 39, 42, 44, 47, 48, 50};

	printf("searchInsert(arr, 20, 48): %d\n", searchInsert(arr, 20, 48));
	
	return 0;
}
