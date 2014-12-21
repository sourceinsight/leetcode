/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

class Solution 
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) 
    {
        ListNode* slow = head;
        ListNode* fast = head;

        // 先走n步 不能走多余n的数，因为不能保证一定存在，超出链表访问出错
        for (int i = 0; i < n; i++) 
        {
            fast = fast->next;
        }
        if (fast == NULL)
            return head->next;
            
        // 当fast指向最后结点的时候，slow指向倒数第n个结点的前一结点
        // 如果用fast!=NULL作为判断，那么与slow需差n+1步，那么fast要先走n+1步，又回到上面不一定存在的问题
        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return head;
    }
/*  
    ListNode *removeNthFromEnd(ListNode *head, int n) 
    {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* Head = &dummy;
        ListNode* slow = Head;
        ListNode* fast = Head;

        for (int i = 0; i < n; i++) 
        {
            fast = fast->next;
        }

        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return Head->next;
    }
*/
};
