package add_two_numbers

import "../util"

/*
2. 两数相加

给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

type ListNode = util.ListNode

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	dummy := &ListNode{-1, nil}
	cur := dummy

	carry := 0
	for l1 != nil || l2 != nil || carry > 0 {
		num := carry

		if l1 != nil {
			num += l1.Val
			l1 = l1.Next
		}

		if l2 != nil {
			num += l2.Val
			l2 = l2.Next
		}

		carry = num / 10

		cur.Next = &ListNode{Val: num % 10}
		cur = cur.Next
	}

	return dummy.Next
}
