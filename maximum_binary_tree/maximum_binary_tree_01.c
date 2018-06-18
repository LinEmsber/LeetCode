/**
 * Definition for a binary tree root.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode * constructMaximumBinaryTree(int * nums, int numsSize)
{
	int max_num, index_max_num;
	if( numsSize == 0 )
		return NULL;

	find_max_num(nums, numsSize, &max_num, &index_max_num);

	struct TreeNode * root = malloc( sizeof(*root) );
	root->val = max_num;

	/* We do not need to really create arrays for store the left and right subarrays.
	 * The index of the root and the length of both subarrays can help us to ensure and control
	 * their correctness.
	 */
	root->right = constructMaximumBinaryTree(nums + index_max_num + 1, numsSize - 1 - index_max_num);
	root->left = constructMaximumBinaryTree(nums, index_max_num);

	return root;
}

/* Find the maximum number of array.
 * This is a void function, but it will store the results to the arguments.
 */
void find_max_num(int * _nums, int _numsSize, int * _max_num, int * _index_max_num)
{
	int i;
	*_max_num = 0;
	*_index_max_num = 0;

	for ( i = 0; i < _numsSize; i++ ) {
		if( *(_nums + i) > *_max_num ) {
			*_max_num = *(_nums + i);
			*_index_max_num = i;
		}
	}
}
