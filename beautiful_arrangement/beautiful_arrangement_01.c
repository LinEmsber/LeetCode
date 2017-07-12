#include <stdio.h>
#include <stdlib.h>

void swap(int * nums, int i, int j)
{
	int tmp = nums[i];
	nums[i] = nums[j];
	nums[j] = tmp;
	return;
}

void permute(int* nums, int current, int len, int* counter)
{
	if(current == len)
		(*counter)++;

	int i;
	for(i = current; i < len; i++) {

		swap(nums, i, current);

		/* The variable current is the index of array, thus need to be added 1. */
		if( (nums[current] % (current + 1) == 0) || ((current + 1) % nums[current] == 0) ) {
			permute(nums, current + 1, len, counter);
		}

		swap(nums, i, current);
	}
}

int countArrangement(int N)
{
	int i;
	int counter = 0;
	int nums[N];

	for(i = 0; i < N; i++)
		nums[i] = i + 1;

	/* 1. Create a number array which starts from 1 and counts to N sequentially.
	 * 2. Permute all combinations of the number array.
	 * 3. Check the two conditions of each combination: the number at the ith position is divisible
	 * by its index or, the index is divisible by the number at the ith position.
	 */
	permute(nums, 0, N, &counter);

	return counter;
}

int main()
{
	int num_2 = 2;
	int num_5 = 5;
	int num_13 = 13;

	printf("countArrangement(%d): %d\n", num_2, countArrangement(num_2));
	printf("countArrangement(%d): %d\n", num_5, countArrangement(num_5));
	printf("countArrangement(%d): %d\n", num_13, countArrangement(num_13));

	return 0;
}
