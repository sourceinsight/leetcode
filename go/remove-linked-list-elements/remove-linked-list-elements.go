package remove_linked_list_elements

import (
	"../util"
)

/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

type ListNode = util.ListNode

func removeElements(head *ListNode, val int) *ListNode {
	dummy := ListNode{Next: head}
	pre, cur := &dummy, dummy.Next

	for cur != nil {
		if cur.Val == val {
			pre.Next = cur.Next
		} else {
			pre = cur
		}
		cur = cur.Next
	}

	return dummy.Next
}
