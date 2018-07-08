int * findDuplicates(int * nums, int numsSize, int * returnSize)
{
	int i, j;
	int * answer = (int *) malloc((numsSize >> 1) * sizeof(int));
	*returnSize = 0;

	for (i = 0; i < numsSize; ++i) {

		/* Since 1 <= a[i]; <= n, thus, it needs to minus 1. */
		j = abs(nums[i]) - 1;

		/* The first time the number will be converted to negative.
		 * We can check this number is shown twice, if it is negative.
		 * And then, add this number into answer and add 1 to returnSize.
		 */
		if (nums[j] < 0){
			answer[(*returnSize)] = j + 1;
			(*returnSize)++;
		} else {
			nums[j] = -nums[j];
		}
	}

	return answer;
}
