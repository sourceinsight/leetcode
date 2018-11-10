package remove_duplicates_from_sorted_list

import (
	"../util"
)

/*
83. 删除排序链表中的重复元素

给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3
*/

type ListNode = util.ListNode

func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	cur, next := head, head.Next

	for next != nil {
		if next.Val == cur.Val {
			cur.Next = next.Next // 删除next
			// cur 不动，next前移继续判断
			next = next.Next
		} else { // 不等，同时前移
			cur = next
			next = next.Next
		}
	}

	return head // head不会变
}
