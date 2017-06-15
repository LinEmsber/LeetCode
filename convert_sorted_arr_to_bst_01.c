#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
};

struct TreeNode * sorted_arr_to_bst(int * nums, int start, int end)
{
	if(start > end)
		return NULL;

	int mid = (start + end) / 2;
	struct TreeNode * node = (struct TreeNode *)malloc(sizeof(struct TreeNode));

	node->val = nums[mid];
	node->left = sorted_arr_to_bst(nums, start, mid - 1);
	node->right = sorted_arr_to_bst(nums, mid + 1, end);

	return node;
}


struct TreeNode* sortedArrayToBST(int* nums, int numsSize) 
{
	return sorted_arr_to_bst(nums, 0, numsSize-1);
}

int main()
{
	int sorted_arr[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

	struct TreeNode * bst = sortedArrayToBST(sorted_arr, 12);

	return 0;
}
