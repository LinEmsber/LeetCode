/* binary tree */
#include <stdio.h>
#include <stdlib.h>

typedef struct bt_node_s{
	int val;
	void *data;
	bt_node_t *left;
	bt_node_t *right;
	int count;
}bt_node_t;

void insert_tree_node( bt_node_t ** tree, bt_node_t *item){
	if(!(*tree)){
		*tree = item;
	}

	if ( item->val < (*item)->val ){
		insert_tree_node( &(*tree)->left, item);

	// }else if (item->val >= (*tree)->val){
	}else{
		insert_tree_node( &(*tree)->right, item);
	}
}

void print_tree( bt_node_t *tree){
	if (tree->left)
		print_tree(tree->left);

	printf("%d\n", tree->val);

	if (tree->right)
		print_tree(tree->right);
}


int main(){

	int i;
	bt_node_t *curr, *root;

	for (i=0; i<times; i++){
		curr = (bt_node_t *) malloc (sizeof (bt_node_t));
		curr -> left = curr -> right = NULL;
		curr -> val = rand();
		insert_tree_node(&root, curr);
	}

	print_tree(root);
	return 0;
}
