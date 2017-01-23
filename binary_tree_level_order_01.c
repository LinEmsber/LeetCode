// Definition for a binary tree node.
struct TreeNode {
        int val;
        struct TreeNode *left;
        struct TreeNode *right;
};

/* 
 *
 *
 *
 */
void traverse(struct TreeNode *root, int depth, int ***arr, int **columnSizes, int *returnSize)
{
        if (!root)
                return;

        if (*returnSize < depth + 1) {
                *returnSize = depth + 1;

                // void *realloc(void *ptr, size_t size);
                // If the new size is larger than the old size, the added memory will not be initialized.
                // allocate memory of one pointer size for *arr, and initialize it.
                *arr = realloc(*arr, (depth + 1) * sizeof(int *));
                (*arr)[depth] = NULL;

                *columnSizes = realloc( *columnSizes, (depth + 1) * sizeof(int) );
                (*columnSizes)[depth] = 0;
        }

        (*arr)[depth] = realloc( (*arr)[depth], ((*columnSizes)[depth] + 1) * sizeof(int) );
        (*arr)[depth][ (*columnSizes)[depth] ] = root->val;

        // move to the next
        ++(*columnSizes)[depth];

        traverse(root->left, depth + 1, arr, columnSizes, returnSize);
        traverse(root->right, depth + 1, arr, columnSizes, returnSize);
}

/**
 * @root: the root of tree
 * @columnSizes: The sizes of the arrays are returned as *columnSizes array.
 * @returnSize: An array of arrays of as returnSize.
 *
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **levelOrder(struct TreeNode *root, int **columnSizes, int *returnSize)
{
        // pointer to pointer array for saving the result.
        int **arr;

        // initialize
        arr = NULL;
        *returnSize = 0;

        traverse(root, 0, &arr, columnSizes, returnSize);

        return arr;
}
