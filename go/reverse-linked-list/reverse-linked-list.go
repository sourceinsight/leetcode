package reverse_linked_list

import "fmt"

/*
Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively.
Could you implement both?
*/

type ListNode struct {
	Val  int
	Next *ListNode
}

// 头插法，就倒置了
func reverseList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	dummy := &ListNode{-1, head}
	cur := head.Next // 第二个结点，从第二个结点开始，头插法
	head.Next = nil  // 倒置后的尾结点

	for cur != nil {
		tmp := cur.Next

		cur.Next = dummy.Next
		dummy.Next = cur

		cur = tmp
	}

	return dummy.Next
}
