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


node_t* merge_list(node_t* l_1, node_t* l_2) {

	if(l_1 == NULL) return l_2;
	if(l_2 == NULL) return l_1;

	node_t *tmp = (node_t*) malloc (sizeof(node_t));
	tmp -> next = NULL;

	node_t *current = tmp;

	while (l_1 != NULL && l_2 != NULL){

		// If value of l_1 less than value of l_2.
		if (l_1 -> val < l_2 -> val){

			// The current is spliced by l_1.
			current -> next = l_1;

			// poll the next node in l_1.
			l_1 = l_1->next;

		}else{

			current -> next = l_2;
			l_2 = l_2->next;

		}

		current = current -> next;
	}

	// If any one of list is polled to the end, splicing the last node of another list into current node.
	if (l_1 == NULL){
		current -> next = l_2;

	}else if (l_2 == NULL){
		current -> next = l_1;

	}

	// splice the last node with NULL.
	current = tmp->next;

	free(tmp);
	return current;
}
