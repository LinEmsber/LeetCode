/* There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24. */
//
// Definition for a binary tree node.
// struct TreeNode
// {
// 	int val;
// 	struct TreeNode *left;
// 	struct TreeNode *right;
// }
//
//	   3
//	  / \
//	 9  20
//	    / \
//	   15  7

int sumOfLeftLeaves(struct TreeNode* root)
{
	int sum = 0;

	if (root == NULL)
		return 0;

	if (root != NULL){

		// check left side first
		if (root -> left != NULL){

			// check the exist of the deeper left leaves
			if( root -> left -> left == NULL && root -> left -> right == NULL){
				sum += root -> left -> val;
			}else{
				sum += sumOfLeftLeaves(root -> left);
			}
		}


		if (root -> right != NULL){
			sum += sumOfLeftLeaves(root -> right);
		}
	}

	return sum;
}
