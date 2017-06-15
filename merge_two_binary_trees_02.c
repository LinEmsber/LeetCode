/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode * mergeTrees(struct TreeNode * t1, struct TreeNode * t2) 
{
	if(t1 == NULL) 
		return t2;

	else if(t2 == NULL) 
		return t1;

	struct TreeNode * t3 = (struct TreeNode *) malloc( sizeof(struct TreeNode) );

	t3->val = t1->val + t2->val;

	t3->left = mergeTrees(t1->left, t2->left);
	t3->right = mergeTrees(t1->right, t2->right);

	return t3;
} 
