package diameter_of_binary_tree

import (
    "../util"
)
/*
Given a binary tree, you need to compute the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \
      4   5
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
*/


// 问题：二叉树的直径，任意两节点的最长路径
// 想法：此题有点怪


// 只有一个节点可以同时使用左子树右子树，转折节点

type TreeNode = util.TreeNode

func diameterOfBinaryTree(root *TreeNode) int {
    result := 0
    lp(root, &result)
    return result
}

// 定义为，此节点下的最大长度
func lp(root *TreeNode, result *int) int {
    if root == nil {
        return -1
    }

    l := lp(root.Left, result) + 1
    r := lp(root.Right, result) + 1
    *result = max(*result, l+r)

    return max(l, r)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}






