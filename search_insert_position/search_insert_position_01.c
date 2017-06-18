/* Search Insert Position */

#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target) 
{
	int low = 0, high = numsSize - 1;
	int mid;

	while (low <= high) {
		mid = low + (high - low) / 2;

		if (nums[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return low;
}


int main()
{
	int arr[20] = {2, 5, 9, 10, 11, 13, 15, 17, 20, 23, 
			25, 28, 31, 32, 39, 42, 44, 47, 48, 50};

	printf("searchInsert(arr, 20, 48): %d\n", searchInsert(arr, 20, 48));
	
	return 0;
}
