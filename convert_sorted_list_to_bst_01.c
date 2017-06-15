/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/* The global pointer points to the current list node for us, and we can easier to 
 * obtain its value.
 */
struct ListNode * list;
struct TreeNode * construct(int length)
{
	if(length <= 0)
		return NULL;

	struct TreeNode * current = (struct TreeNode *)malloc(sizeof(struct TreeNode));

	current->left = construct(length >> 1);
	current->val = list->val;
	list = list->next;
	current->right = construct(length - (length >> 1) - 1);

	return current;
}

struct TreeNode * sortedListToBST(struct ListNode * head)
{
	int i, length = 0;
	struct ListNode * p = head;

	/* count the length of the list. */
	while(p != NULL) {
		length++;
		p = p->next;
	}
	
	/* convert the sorted list to bst from the head node. */
	list = head;

	return construct(length);
}
