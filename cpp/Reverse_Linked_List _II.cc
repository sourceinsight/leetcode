/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
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
    // 画图推倒，一目了然
    ListNode *reverseBetween(ListNode *head, int m, int n) 
    {
        if (head == NULL || m >= n)
            return head;
            
        ListNode dummy(0);
        dummy.next = head;
        ListNode* pPrev = &dummy;
        
        for (int i = 0; i < m-1; i++)
            pPrev = pPrev->next;
        
        ListNode* pCur = pPrev->next;
        for (int i = 0; i < n-m; i++)
        {
            ListNode* pNext = pCur->next;
            
            pCur->next = pNext->next;
            pNext->next = pPrev->next;
            pPrev->next = pNext;
            
        }
        
        return dummy.next;
    }
};
