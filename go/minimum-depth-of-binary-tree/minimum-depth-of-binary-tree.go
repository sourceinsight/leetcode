package minimum_depth_of_binary_tree

import (
	"../util"
)

/*
111. 二叉树的最小深度

给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。

示例:

给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回它的最小深度  2.
*/

type TreeNode = util.TreeNode

func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}

	// 注意这两种情况
	/*
			1
		2
		这颗子树的高度是1，而不是0
	*/
	if root.Left == nil {
		return 1 + minDepth(root.Right)
	}
	if root.Right == nil {
		return 1 + minDepth(root.Left)
	}

	return 1 + min(minDepth(root.Left), minDepth(root.Right))
}

func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}
