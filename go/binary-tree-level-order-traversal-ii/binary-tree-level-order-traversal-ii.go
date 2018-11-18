package binary_tree_level_order_traversal_ii

import (
	"../util"
)

/*
107. 二叉树的层次遍历 II

给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]
*/

type TreeNode = util.TreeNode

func levelOrderBottom(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}

	result := make([][]int, 0)
	queue := make([]*TreeNode, 0)
	queue = append(queue, root)

	for len(queue) > 0 {
		level := make([]int, 0)

		l := len(queue)
		for i := 0; i < l; i++ {
			cur := queue[0]
			queue = queue[1:]
			level = append(level, cur.Val)

			if cur.Left != nil {
				queue = append(queue, cur.Left)
			}
			if cur.Right != nil {
				queue = append(queue, cur.Right)
			}
		}
		result = append([][]int{level}, result...)
	}

	return result
}
