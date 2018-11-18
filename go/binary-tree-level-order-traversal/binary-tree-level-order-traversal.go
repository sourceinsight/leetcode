package binary_tree_level_order_traversal

import (
	"../util"
)

/*
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
*/

type TreeNode = util.TreeNode

func levelOrder(root *TreeNode) [][]int {
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
		result = append(result, level)
	}

	return result
}
