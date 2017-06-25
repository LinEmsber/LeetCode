/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// simple dirgram of binary search tree:
//
// 		20
// 	/		\
// 	8		22
//
// /		\
// 4		12
//
// 	/		\
// 	10		14
//

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{

	// if else method, 24ms

        // if (root->val > p->val && root->val > q->val){
        //     return lowestCommonAncestor(root->left, p, q);
        // }else if (root->val < p->val && root->val < q->val){
        //     return lowestCommonAncestor(root->right, p, q);
        // }
        // return root;


        // iterative method, 24ms

        if (p->val > q->val){
		struct TreeNode *temp;
		temp = p;
		p = q;
		q = temp;
        }

        while ( !(root->val >= p->val && root->val <= q->val) ){
		if (root->val < p->val){
			root = root -> right;
		}else if (root->val > q->val){
			root = root -> left;
		}
        }
        return root;
}
