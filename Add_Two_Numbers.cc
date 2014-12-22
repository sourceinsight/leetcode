/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
    {
        ListNode* head = NULL;
        ListNode** pCur = &head;
        
        int carry = 0;
        while (l1 != NULL && l2 != NULL)
        {
            ListNode* tmp = new ListNode((l1->val + l2->val + carry) % 10);
            *pCur = tmp;
            pCur = &((*pCur)->next);
            carry = (l1->val + l2->val + carry) / 10;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1 != NULL)
        {
            ListNode* tmp = new ListNode((l1->val + carry) % 10);
            *pCur = tmp;
            pCur = &((*pCur)->next);
            carry = (l1->val + carry) / 10;
            
            l1 = l1->next;
        }
        
        while (l2 != NULL)
        {
            ListNode* tmp = new ListNode((l2->val + carry) % 10);
            *pCur = tmp;
            pCur = &((*pCur)->next);
            carry = (l2->val + carry) / 10;
            
            l2 = l2->next;
        }
        
        if (carry > 0)
        {
            ListNode* tmp = new ListNode(carry);
            *pCur = tmp;
        }
        
        return head;
    }
/*
    // 增加一个dummy head。优化处理流程
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode* pCur = &dummy;
        
        int carry = 0;
        while (l1 != NULL || l2 != NULL)
        {
            ListNode* tmp = new ListNode((getValue(l1) + getValue(l2) + carry) % 10);
            pCur->next = tmp;
            pCur = pCur->next;
            
            carry = (getValue(l1) + getValue(l2) + carry) / 10;
            if (l1 != NULL)
                l1 = l1->next;
            if (l2 != NULL)
                l2 = l2->next;
        }
        
        if (carry > 0)
        {
            ListNode* tmp = new ListNode(carry);
            pCur->next = tmp;
        }
        
        return dummy.next;
    }
private:
    int getValue(ListNode* &l)
    {
        int ret = 0;
        if (l != NULL)
        {
            ret = l->val;
        }
        return ret;
    }
*/
};
