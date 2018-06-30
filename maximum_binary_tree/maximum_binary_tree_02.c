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

struct TreeNode * constructMaximumBinaryTree(int * nums, int numsSize)
{
	if( numsSize == 0 )
		return NULL;

	/* Find the maxium number and its index of array. */
	int index_max_num = 0, max_num = 0;
	for ( int i = 0; i < numsSize; i++ ){
		if ( *(nums + i) > max_num ){
			max_num = *(nums + i);
			index_max_num = i;
		}
	}

	struct TreeNode * root = malloc( sizeof(*root) );
	root->val = max_num;
	root->right = constructMaximumBinaryTree(nums + index_max_num + 1, numsSize - 1 - index_max_num);
	root->left = constructMaximumBinaryTree(nums, index_max_num);

	return root;
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
