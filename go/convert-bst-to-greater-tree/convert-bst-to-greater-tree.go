package convert_bst_to_greater_tree

import (
    "../util"
)

/*
Given a Binary Search Tree (BST), convert it to a Greater Tree
such that every key of the original BST is changed to the original key
plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
*/

type TreeNode = util.TreeNode

func convertBST(root *TreeNode) *TreeNode {
    sum := 0

    travel(root, &sum)
    return root
}

// 右-中-左 遍历
func travel(root *TreeNode, sum *int) {
    if root == nil {
        return
    }

    travel(root.Right, sum)
    root.Val += *sum
    *sum = root.Val
    travel(root.Left, sum)
}
