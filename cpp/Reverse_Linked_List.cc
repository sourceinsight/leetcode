/*
Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
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
    ListNode* reverseList(ListNode* head) 
    {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode* pPre = NULL;
        ListNode* pCur = head;
        ListNode* pNext = pCur->next;
        
        while (pCur != NULL)
        {
            pNext = pCur->next; 
            pCur->next = pPre; 
            pPre = pCur;
            pCur = pNext;
        }
        head = pPre;
        
        return head;
    }
};
