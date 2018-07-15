int * findDuplicates(int * nums, int numsSize, int * returnSize)
{
	int i, tmp;
	int * answer = (int *) malloc((numsSize >> 1) * sizeof(int));
	*returnSize = 0;

	for (i = 0; i < numsSize; ++i) {

		/* Since 1 <= a[i] <= n, and the index of the numbs is zero base.
		 * Thus, it needs to minus 1. 
		 */
		tmp = abs(nums[i]) - 1;

		/* The idea is we do a linear pass using the input array itself as a hash
		 * to store which numbers have been seen before. 
		 */
		if (nums[tmp] < 0){
			answer[(*returnSize)] = tmp + 1;
			(*returnSize)++;
		} else {
			nums[tmp] = -nums[tmp];
		}
	}

	return answer;
}
