#include <stdio.h>
#include <stdlib.h>

void moveZeroes(int * nums, int numsSize)
{
        int i, k = 0;
        for ( i = 0; i < numsSize; i++) {
            if(nums[i] == 0)
                continue;
            if(k != i) 
                nums[k] = nums[i];
            k++;
        }
        for(; k < numsSize; k++)
            nums[k] = 0;
}

int main()
{
	int arr_1[6] = {8, 0, 0, 1, 2, 7};
	moveZeroes(arr_1, sizeof(arr_1) / sizeof(arr_1[0]));
}
