#include <stdio.h>
#include <stdlib.h>


int arrayPairSum(int* nums, int numsSize)
{
	int i;
	int sum = 0;
	int flag = 1;

	/* All the integers in the array will be in the range of [-10000, 10000]. */
	int temp_nums[20001];
	memset(temp_nums, 0, sizeof(temp_nums));

	/* Store the mark of numbers in temp_nums, it represents that the number is exist.
	 * The mark of the negative numbers are store in range from 0 to 9999, and the mark of the positive
	 * numbers are store from 10001 to 20000.
	 */
	for(i = 0; i < numsSize; i++){
		temp_nums[nums[i] + 10000]++;
	}


	/* 1. If some number is exist, add it to sum and turn the flag to 0, and turn the mark of number to 0.
	 * 2. The temp_nums[i] becomes 0, the i++, go to the next loop.
	 * 3. The flag will flip between 0 and 1 when the temp_nums[i] is exist.
	 */
	for(i = 0; i < 20001; ){

		if(temp_nums[i]){

			/* If the flag is 1, add the number to sum, and trun tha flag to 0.
			 * The next exist number will not be added to sum, but turn the flag to 1.
			 */
			if(flag){
				sum += (i-10000);
				flag = 0;
			}else{
				flag = 1;
			}
			temp_nums[i]--;
		}else{
			i++;
		}
	}

	return sum;
}


int main()
{
	int number_array[20] = {93, 10, 40, 50, 99, 18, 24, 52, 12, 83,
		56, 11, 72, 77, 90, 15, 26, 7, 64, 82};

	int result;

	printf("sizeof(number_array): %zu\n", sizeof(number_array));

	result = arrayPairSum(number_array, 20);
	printf("result: %d\n", result);

	return 0;
}
