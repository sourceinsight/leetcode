package path_sum

/*
Given a binary tree and a sum,
determine if the tree has a root-to-leaf path such that
adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/

type TreeNode struct {
    Val   int
    Left  *TreeNode
    Right *TreeNode
}

func hasPathSum(root *TreeNode, sum int) bool {
    return hasPathSumImpl(root, sum, 0)
}

func hasPathSumImpl(root *TreeNode, sum int, cur int) bool {
    if root == nil {
        return false
    }

    cur += root.Val
    if root.Left == nil && root.Right == nil { // 叶子节点
        return cur == sum
    }

    return hasPathSumImpl(root.Left, sum, cur) || hasPathSumImpl(root.Right, sum, cur)
}

// ----------

func hasPathSum2(root *TreeNode, sum int) bool {
    return hasPathSumImpl(root, sum)
}

func hasPathSumImpl2(root *TreeNode, sum int) bool {
    if root == nil {
        return false
    }

    sum -= root.Val // 剩下的sum
    if root.Left == nil && root.Right == nil { // 叶子节点
        return sum == 0
    }

    return hasPathSumImpl(root.Left, sum) || hasPathSumImpl(root.Right, sum)
}