package sum_of_left_leaves

import (
	"../util"
)

/*
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
*/

type TreeNode = util.TreeNode

func sumOfLeftLeaves(root *TreeNode) int {
	if root == nil {
		return 0
	}

	if root.Left == nil {
		return sumOfLeftLeaves(root.Right)
	}

	ret := 0
	// 左侧叶子节点
	if root.Left.Left == nil && root.Left.Right == nil {
		ret += root.Left.Val
	}
	return ret + sumOfLeftLeaves(root.Left) + sumOfLeftLeaves(root.Right)
}
