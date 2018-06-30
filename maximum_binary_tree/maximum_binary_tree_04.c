#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
};

/* Functions. */
struct TreeNode * new_node(int _data);
struct TreeNode * array_to_tree_level_order(int array[], int index, int length);
void print_tree_level_order(struct TreeNode * root);
void print_tree_given_level(struct TreeNode * root, int level);
int tree_height(struct TreeNode * node);

struct TreeNode * constructMaximumBinaryTree(int * nums, int numsSize);

/* Input a integer value and create a tree node. */
struct TreeNode * new_node(int _data)
{
	struct TreeNode * node = malloc(sizeof(* node));
	node->val = _data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

/* Construct a complete binary tree from given array in level order. */
struct TreeNode * array_to_tree_level_order(int array[], int index, int length)
{
	if (index < length){
		struct TreeNode * root = new_node(array[index]);

		root->left = array_to_tree_level_order(array, index * 2 + 1, length);
		root->right = array_to_tree_level_order(array, index * 2 + 2, length);

		return root;
	} else {
		return NULL;
	}
}

/* Print tree in level order. */
void print_tree_level_order(struct TreeNode * root)
{
	int h = tree_height(root);
	for ( int i = 1; i <= h; i++ )
		print_tree_given_level(root, i);
}

/* Print tree in given level. */
void print_tree_given_level(struct TreeNode * root, int level)
{
	if (root == NULL)
		return;

	if (level == 1){
		printf("%d ", root->val);
	} else if (level > 1) {
		print_tree_given_level(root->left, level - 1);
		print_tree_given_level(root->right, level - 1);
	} else {
		printf("Error\n");
	}
}

int tree_height(struct TreeNode * node)
{
	if ( NULL == node ){
		return 0;
	} else {
		/* Compute the height of each subtree */
		int l_height = tree_height(node->left);
		int r_height = tree_height(node->right);

		/* Use the larger one */
		if (l_height > r_height)
			return l_height + 1;
		else
			return r_height + 1;
	}
}

/* Give the start and end index to find the index of maximun number from the integer array. */
int find_index_max_num(int * nums_array, int start, int end)
{
	int i;
	int index_max_num = start;

	/* Compare the numbers of array from the second index to the end index. */
	for( i = start + 1; i <= end; i++ )
		if( nums_array[index_max_num] < nums_array[i] )
			index_max_num = i;

	return index_max_num;
}

/* 1. Create a tree node.
 * 2. Search the index of maximun number from the array.
 * 3. Use binary method to separate the array.
 * 4. If the start index equeals the end index, we do not need to search the index
 * of the maximun number.
 */
struct TreeNode * helper_function(int * nums, int start, int end)
{
	struct TreeNode * root = malloc(sizeof(struct TreeNode));

	if ( start == end)  {
		root->val = nums[start];
		root->left = NULL;
		root->right = NULL;

	} else {
		// int index_max_num = find_index_max_num(nums, start, end);
		int index_max_num = start;
		for( int i = start + 1; i <= end; i++ )
			if( nums[index_max_num] < nums[i] )
				index_max_num = i;

		root->val = nums[index_max_num];

		/* If the index of start equals index_max_num, it means there is no
		 * tree node will be stored in the left subtree.
		 * We only need to focus on start+1 index to end index.
		 */
		if(index_max_num == start)
			root->left = NULL;
		else
			root->left = helper_function(nums, start, index_max_num - 1);

		/* If the index of end equals index_max_num, there is nothing will on
		 * the right subtree.
		 */
		if(index_max_num == end)
			root->right = NULL;
		else
			root->right = helper_function(nums, index_max_num + 1, end);
	}

	return root;
}

/* Use a helper function to use another algorithm.
* But the interface of function need to be modified.
*/
struct TreeNode * constructMaximumBinaryTree(int * nums, int numsSize)
{
    return helper_function(nums, 0, numsSize - 1);
}


int main()
{
	int input_arr[] = {3, 2, 1, 6, 0, 5};
	int input_arr_len = sizeof(input_arr) / sizeof(input_arr[0]);

	for (int i = 0; i < input_arr_len; i++)
		printf("%d ", input_arr[i]);
	printf("\n");

	struct TreeNode * simple_tree = constructMaximumBinaryTree(input_arr, input_arr_len);

	print_tree_level_order(simple_tree);
	printf("\n");

	return 0;
}
