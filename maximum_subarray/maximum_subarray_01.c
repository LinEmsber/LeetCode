/*
 * https://discuss.leetcode.com/topic/6413/dp-solution-some-thoughts/2
 * https://en.wikipedia.org/wiki/Maximum_subarray_problem
 */

#include <stdio.h>
#include <stdlib.h>

int maxSubArray(int * nums, int numsSize)
{
        int i;
	int b = 0, sum = nums[0];

	for(i = 0; i < numsSize; i++) {
		if(b > 0)
			b += nums[i];
		else
			b = nums[i];
		if(b > sum)
			sum = b;
	}
	return sum;
}

int main()
{
	int array_1[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int array_2[13] = {17, -3, -10, 5, 43, 2, 100, -83, 2, 30, -1, -333, 13};

        printf("maxSubArray(&array_1, array_1_len): %d\n", maxSubArray((int *)&array_1, 9));
        printf("maxSubArray(&array_2, array_2_len): %d\n", maxSubArray((int *)&array_2, 13));

        return 0;
}
