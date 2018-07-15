int * findDuplicates(int * nums, int numsSize, int * returnSize)
{
	int i;

	/* The maximun size of the repeated number is half of numsSize. */
	int * answer = (int *) malloc( (numsSize >> 1) * sizeof(int) );
	*returnSize = 0;

	/* Create integer map and initialize it. 
	 * Use the number as an index to save them into an array.
	 * But the index of an array is zero base, thus, it needs to add one for easier to use.
	 */
	int int_map[1 + numsSize];
	for(i = 1; i <= numsSize; i++)
		int_map[i] = 0;

	for(i = 0; i < numsSize; i++)
		int_map[nums[i]]++;

	for(i = 1; i <= numsSize; i++){
		if( int_map[i] >= 2 ){
			answer[*returnSize] = i;
			(*returnSize)++;
		}
	}

	return answer;
}
