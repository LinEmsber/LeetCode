/* is_same_tree */

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    // if (p && q)
    //     return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && (p->val == q->val)? true : false);
    // else if(!p && !q)
    //     return true;
    // else
    //     return false;

    return ((p && q) && (isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && (p->val == q->val)? true : false)) || (!p && !q);
}
