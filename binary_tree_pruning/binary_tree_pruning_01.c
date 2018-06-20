#include <stdio.h>
#include <stdlib.h>

/* The structure of tree node. */
struct TreeNode
{
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
};

/* Functions. */
struct TreeNode * new_node(int _data);
struct TreeNode * array_to_tree_level_order(int array[], struct TreeNode * root, int index, int length);
void print_tree_level_order(struct TreeNode * root);
void print_tree_given_level(struct TreeNode * root, int level);
int tree_height(struct TreeNode * node);
struct TreeNode * pruneTree(struct TreeNode * root);

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
struct TreeNode * array_to_tree_level_order(int array[], struct TreeNode * root, int index, int length)
{
	if (index < length){
		struct TreeNode * tmp = new_node(array[index]);
		root = tmp;
		root->left = array_to_tree_level_order(array, root->left, index * 2 + 1, length);
		root->right = array_to_tree_level_order(array, root->right, index * 2 + 2, length);
	}
	return root;
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
		if (l_height > r_height){
                        return(l_height + 1);
                } else {
                        return(r_height + 1);
                }
	}
}

struct TreeNode * pruneTree(struct TreeNode * root)
{
	if ( NULL == root )
		return root;

	/* Follow both child node to prun this tree. */
	root->left = pruneTree(root->left);
	root->right = pruneTree(root->right);

	/* If the node is the leaf node. */
	if (root->val == 0 && root->left == NULL && root->right == NULL)
		return NULL;

	return root;
}

int main()
{
	// int int_arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
        int int_arr[] = {1, 0, 1, 0, 0, 0, 1};
	int array_length = sizeof(int_arr) / sizeof(int_arr[0]);

        /* Convert the integer array into the binary tree. */
	struct TreeNode * root = array_to_tree_level_order(int_arr, root, 0, array_length);
        print_tree_level_order(root);
        printf("\n");

        /* Prune the tree. */
        pruneTree(root);
	print_tree_level_order(root);
	printf("\n");

	return 0;
}
