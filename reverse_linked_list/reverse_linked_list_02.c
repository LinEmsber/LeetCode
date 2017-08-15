/* Recursive method */
#include <stdio.h>
#include <stdlib.h>

#define NODE_NUMS 10

struct ListNode {
	int data;
	struct ListNode * next;
};

/* Create a node. */
struct ListNode * node_create(int value)
{
	struct ListNode * n;

	n = malloc( sizeof(*n) );
	if (n == NULL)
		return NULL;

	n->data = value;
	n->next = NULL;

	return n;
}

/* Add a new node. */
int node_insert(struct ListNode * head, struct ListNode * n)
{
	if (head == NULL || n == NULL)
		return -1;

	n->next = head->next;
	head->next = n;

	return 0;
}

/* Print the list. */
int print_list(struct ListNode * head)
{
	if (head == NULL)
		return -1;

	struct ListNode * current = head;

	while ( current != NULL ){
		printf("%d ", current->data);
		current = current -> next;
	}
	printf("\n");

	return 0;
}

/* Traversal to the tail node. */
struct ListNode * tail_node(struct ListNode * head)
{
	if ( head == NULL )
		return NULL;

	struct ListNode * current = head;
	struct ListNode * prev = NULL;
	while(current != NULL){
		prev = current;
		current = current->next;
	}
	return prev;
}

/* Use recursive method to reverse linked list.
 * Return the new head.
 */
 struct ListNode * reverseList(struct ListNode* head)
 {
 	if (NULL == head || NULL == head->next)
                 return head;

 	struct ListNode * head_next_tmp = head->next;
 	head->next = NULL;

 	struct ListNode * new_head = reverseList(head_next_tmp);
 	head_next_tmp->next = head;

 	return new_head;
 }

/* Reverse linked list.
 * Retrun 0 for success, and -1 for fail.
 */
int reverseList_return_int(struct ListNode * head)
{
	if(head == NULL)
		return -1;

	struct ListNode * current = head;
	struct ListNode * next = NULL;
	struct ListNode * prev = NULL;

	while ( current != NULL ){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;

	return 0;
}

int main()
{
	int i;
	int ret = 0;

	struct ListNode * p_tail;
        struct ListNode * p_tmp;
	struct ListNode * root = node_create(0);
	struct ListNode * p_element[NODE_NUMS];

	for (i = 0; i < NODE_NUMS; i ++){

		/* Create nodes */
		p_element[i] = node_create(i * 10 + 10);
		if(p_element == NULL)
			printf("error\n");

		/* Insert nodes behind head, FILO */
		ret = node_insert( root, p_element[i] );
		if (ret < 0)
			printf("error\n");
	}

        printf("Original list: \n");
	print_list(root);

        printf("Reverse list: \n");
	p_tail = tail_node(root);
	ret = reverseList_return_int(root);
        if ( ret < 0 )
                return -1;
        print_list( p_tail );

        printf("Reverse list, again: \n");
        p_tmp = reverseList(p_tail);
        print_list(p_tmp);

        return 0;
}
