/* iterative method */

struct ListNode * reverseList(struct ListNode* head)
{
        if(head == NULL)
                return head;

        struct ListNode * pre = NULL;
        struct ListNode * head_next_tmp;

        while(head != NULL){
                head_next_tmp = head->next;
                head->next = pre;
                pre = head;
                head = head_next_tmp;
        }

        return pre;
}
