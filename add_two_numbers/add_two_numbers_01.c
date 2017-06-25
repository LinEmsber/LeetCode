/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode * addTwoNumbers(struct ListNode * l1, struct ListNode * l2)
{
	struct ListNode * list_1 = l1;
	struct ListNode * list_2 = l2;

	struct ListNode * head = NULL;
	struct ListNode * current = NULL;

	int tmp_val_1, tmp_val_2;
	int carry_num, remainder_num;

	while (list_1 != 0 || list_2 != 0 || carry_num != 0) {

		if (current == NULL) {
			current = (struct ListNode *) malloc ( sizeof(struct ListNode) );
			head = current;

		}else {
			current->next = (struct ListNode *) malloc( sizeof(struct ListNode) );
			current->next->val = 0;
			current = current->next;
		}

		tmp_val_1 = (list_1 == NULL) ? 0 : list_1->val;
		tmp_val_2 = (list_2 == NULL) ? 0 : list_2->val;

		remainder_num = (tmp_val_1 + tmp_val_2 + carry_num) % 10;
		carry_num = (tmp_val_1 + tmp_val_2 + carry_num) / 10;

		current->val = remainder_num;
		current->next = NULL;

		list_1 = (list_1 == NULL) ? NULL : list_1->next;
		list_2 = (list_2 == NULL) ? NULL : list_2->next;
	}

	return head;
}
