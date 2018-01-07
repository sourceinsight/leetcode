/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
    ListNode *partition(ListNode *head, int x) 
    {
        ListNode dummy(0), *ins = &dummy, *cur = &dummy;
        dummy.next = head;
        
        while (cur->next != NULL) // 终止循环：cur指向最后结点
        {
            if (cur->next->val >= x)
            {
                cur = cur->next; // ins不动，只cur移动
            }
            else 
            {
                if (cur == ins) 
                {
                    cur = cur->next;
                    ins = ins->next;
                } 
                else 
                {
                    ListNode *tmp = cur->next;
                    cur->next = tmp->next;
                    tmp->next = ins->next;
                    ins->next = tmp;
                    ins = tmp;
                }
            }
        }
        
        return dummy.next;
    }
};
