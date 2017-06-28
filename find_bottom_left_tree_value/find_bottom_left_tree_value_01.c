/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int l_value, max_depth;
void traverse (struct TreeNode * root, int depth)
{
        if (!root)
                return 0;

        /* Traverse the left node before the right node, and we will find the
         * the most bottom left node.
         */
        traverse(root -> left, depth + 1);
        traverse(root -> right, depth + 1);

        /* Check this node is the most bottom node or not. */
        if (max_depth < depth) {
                max_depth = depth;
                l_value = root -> val;
        }
}

int findBottomLeftValue(struct TreeNode * root)
{
        l_value = root -> val;
        max_depth = 0;
        traverse (root, 0);

        return l_value;
}
