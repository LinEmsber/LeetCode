#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * findDisappearedNumbers(int * nums, int numsSize, int * returnSize)
{
        int i;
        int * histogram = (int *) malloc(sizeof(int) * (numsSize+1));
        memset(histogram, 0, sizeof(int) * (numsSize+1));

        for (i = 0; i < numsSize; i++) {
                // printf("%d\n", nums[i]);
                histogram[nums[i]]++;
        }

	/* Set histogram[0] as 1. If we find a disappeared number, we store this number 
	 * at the beginning of histogram[1], and histogram[0] as the length of the disappeared
	 * numbers.
	 */
        histogram[0] = 1;

        for (i = 1; i <= numsSize; i++) {
                if (histogram[i] == 0) {
                        histogram[histogram[0]] = i;
                        histogram[0]++;
                }
        }

        *returnSize = histogram[0] - 1;
        return &histogram[1];
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

