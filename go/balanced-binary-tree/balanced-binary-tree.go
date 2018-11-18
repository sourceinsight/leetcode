package balanced_binary_tree

import (
	"../util"
)

/*
110. 平衡二叉树

给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 。
*/

type TreeNode = util.TreeNode

// 方法一：直观。O(nlogn)
func isBalanced(root *TreeNode) bool {
	if root == nil {
		return true
	}

	lh := height(root.Left)
	rh := height(root.Right)

	return abs(lh-rh) <= 1 && isBalanced(root.Left) && isBalanced(root.Right)

}

func height(root *TreeNode) int {
	if root == nil {
		return 0
	}

	return max(height(root.Left), height(root.Right)) + 1
}

// 方法二：O(n) 计算高度同时判断是否平衡
func isBalanced2(root *TreeNode) bool {
	if root == nil {
		return true
	}

	_, balanced := height2(root)
	return balanced
}

func height2(root *TreeNode) (int, bool) {
	if root == nil {
		return 0, true
	}
	lh, balanced := height2(root.Left)
	if !balanced {
		return 0, false
	}
	rh, balanced := height2(root.Right)
	if !balanced {
		return 0, false
	}
	return max(lh, rh) + 1, abs(lh-rh) <= 1
}

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func abs(x int) int {
	if x >= 0 {
		return x
	}
	return -x
}
