/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
    ListNode *deleteDuplicates(ListNode *head) 
    {
        if (head == NULL || head->next == NULL)
            return head;
            
        ListNode* pPre = head;
        ListNode* pCur = head->next;
        while (pCur != NULL) 
        {
            if (pPre->val == pCur->val)
            {
                pPre->next = pCur->next;
                delete pCur;
            }
            else
            {
                pPre->next = pCur;
                pPre = pPre->next;
            }
            
            pCur = pCur->next;
        }
        
        return head;
    }
};
