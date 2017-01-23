/* recursive method */
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
