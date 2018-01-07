package symmetric_tree

import (
    "../util"
)

/*
Given a binary tree, check whether it is a mirror of itself
(ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/

// 问题：是否是对称树

type TreeNode = util.TreeNode

func isSymmetric(root *TreeNode) bool {
    if root == nil {
        return true
    }

    return symmetric(root.Left, root.Right)
}

func symmetric(left *TreeNode, right *TreeNode) bool {
    if left == nil && right == nil {
        return true
    }
    // 只有一个是nil
    if left == nil || right == nil {
        return false
    }

    if left.Val != right.Val {
        return false
    }

    return symmetric(left.Left, right.Right) && symmetric(left.Right, right.Left)
}
