package convert_sorted_list_to_binary_search_tree

import (
    "../util"
    "../convert-sorted-array-to-binary-search-tree"
)

/*
Given a singly linked list where elements are sorted in ascending order,
convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree
in which the depth of the two subtrees of every node never differ by more than 1.


Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
*/

type ListNode = util.ListNode
type TreeNode = util.TreeNode

// 一种方法直接链表变数组，然后利用convert-sorted-array-to-binary-search-tree.go
func sortedListToBST(head *ListNode) *TreeNode {
    arr := []int{}
    for head != nil {
        arr = append(arr, head.Val)
        head = head.Next
    }

    return convert_sorted_array_to_binary_search_tree.SortedArrayToBST(arr)
}

// 方法2： 找到中间位置，一个slow,一个fast， slow走一步，fast走两步

