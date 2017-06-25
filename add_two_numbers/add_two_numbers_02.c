/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	int carry_num = 0, num = 0;
	struct ListNode * current = NULL, * head = NULL, * node = NULL;

	while(l1 || l2 || carry_num) {

		node = malloc(sizeof(struct ListNode));
		num = 0;

		if(l1) {
			num += l1->val;
			l1 = l1->next;
		}

		if(l2) {
			num += l2->val;
			l2 = l2->next;
		}

		num += carry_num;

		node->val = num % 10;
		node->next = NULL;

		carry_num = num / 10;

		if(!head){
			head = current = node;
		} else {
			current->next = node;
			current = current->next;
		}
	}

	return head;
}
