package merge_two_sorted_lists

/*
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil && l2 == nil {
		return nil
	}

	if l1 == nil {
		return l2
	} else if l2 == nil {
		return l1
	}

	iter1, iter2 := l1, l2
	head := &ListNode{0, nil} // 空头，好用
	it := head

	for iter1 != nil && iter2 != nil {
		if iter1.Val <= iter2.Val {
			it.Next = iter1
			iter1 = iter1.Next
		} else {
			it.Next = iter2
			iter2 = iter2.Next
		}

		it = it.Next
	}

	if iter1 == nil {
		it.Next = iter2
	} else {
		it.Next = iter1
	}

	return head.Next
}
