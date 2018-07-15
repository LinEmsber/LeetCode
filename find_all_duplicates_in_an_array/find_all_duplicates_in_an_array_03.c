/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * findDuplicates(int * nums, int numsSize, int * returnSize)
{
	/* Create a hash table and initialize it.
	 * The index of an array is zero base, thus, it needs to add one for easier to use.
	 */
	int * hash_table = (int *) malloc( sizeof(int) * (numsSize + 1) );
	memset(hash_table, 0, sizeof(int) * (numsSize +1));

	*returnSize = 0;
	int * answer = (int *) malloc( sizeof(int) * numsSize );

	for(int i = 0; i < numsSize; i++){
		hash_table[nums[i]]++;

		if(hash_table[nums[i]] == 2){
			answer[ (*returnSize)++ ] = nums[i];
		}
	}

	return answer;
}
