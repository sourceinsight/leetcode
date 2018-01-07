/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
        
        // 加个dummy结点，方便处理。比如把头删掉了，处理起来会麻烦些。
        ListNode dummy(INT_MIN);
        dummy.next = head;
        
        ListNode* pPrev = &dummy;
        ListNode* pCur = head;
        ListNode* pNext = head->next;
        
        
        while (pNext != NULL)
        {
            if (pNext->val == pCur->val)
            {
                while ((pNext = pNext->next)  != NULL &&  pNext->val == pCur->val);
                
                // 释放内存  
                ListNode* p1 = pPrev->next;
                ListNode* p2 = NULL;
                while (p1 != pNext)
                {
                    p2 = p1;
                    p1 = p1->next;
                    delete p2;
                }
                
                if (pNext == NULL)
                {
                    pPrev->next = NULL;
                }
                else
                {
                    pPrev->next = pNext;
                    pCur = pNext;
                    pNext = pNext->next;
                }
            }
            else
            {
                pPrev = pCur;
                pCur = pNext;
                pNext = pNext->next;
            }
        }
        
        return dummy.next;
    }
};
