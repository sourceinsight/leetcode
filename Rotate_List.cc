/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode *rotateRight(ListNode *head, int k) 
    {
        if (head == NULL || k <= 0)
            return head;
            
        // 得到链表长度
        int len = 1;
        ListNode* p1 = head;
        while (p1->next != NULL)
        {
            p1 = p1->next;
            len++;
        }
        
        k = k % len; // 这里排除了一种k==len时会造成 形成了环 的情况。k==len，k=0;
        
        // 这里想要到达 前一结点。就要想到是否存在前一结点。那么设一dummy结点。
        ListNode dummy(0), *p2 = &dummy;
        dummy.next = head;
        
        for (int i = 0; i < len-k; i++)
            p2 = p2->next;
        
        p1->next = head;
        head = p2->next;
        p2->next = NULL;
        
        return head;
    }
};
