/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode* slow = head, *fast = head;
        ListNode* tmp = NULL;
        
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast)
            {
                tmp = head; // 出发，相遇时在交点处
                while (tmp != slow)
                {
                    tmp = tmp->next;
                    slow = slow->next;
                }
                return tmp;
            }
        }
        
        return NULL;
    }
};
