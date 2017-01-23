/*
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
 */


typedef struct node node_t;

struct node
{
	int val;
	struct node * next;
};


node_t * merge_list(node_t* l_1, node_t* l_2)
{
        if(!l_1) return l_2;
        if(!l_2) return l_1;

        return l_1->val <= l_2->val ? ( l_1->next = merge_list(l_1->next, l_2), l_1 ) : ( l_2->next = merge_list(l_2->next, l_1), l_2 );
}
