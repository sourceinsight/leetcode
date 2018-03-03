package path_sum_ii

import (
	"../util"
)

/*
Given a binary tree and a sum,
find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/

type TreeNode = util.TreeNode

func pathSum(root *TreeNode, sum int) [][]int {
	result := make([][]int, 0, 64)
	path := make([]int, 0, 64)
	dfs(root, sum, path, &result)
	return result
}

func pathSum2(root *TreeNode, sum int) [][]int {
	result := make([][]int, 0, 64)
	path := make([]int, 0, 64)
	dfs2(root, sum, &path, &result)
	return result
}

// c++和golang差别还是很大的。c++有引用
// 1. go这里result只能用二维slice的指针，因为二维slice可能append后会变，用指针始终指向它。
// 2. path添加进result时，也必须拷贝path，c++的vector的push_back是值拷贝，不需要我们自己动手拷贝了。
// 3. path为什么这里没有像result一样用户指针，因为，递归调用，只对当前这层的有用
// 讲了c++,python,java有些不同 https://www.youtube.com/watch?v=zrN2dxtQ0f0
// 理解一下slice, https://jiajunhuang.com/articles/2017_07_18-golang_slice.md.html

func dfs(root *TreeNode, sum int, path []int, result *[][]int) {
	if root == nil {
		return
	}

	sum -= root.Val
	path = append(path, root.Val)
	if root.Left == nil && root.Right == nil {
		if sum == 0 {
			tmp := make([]int, len(path))
			copy(tmp, path)
			*result = append(*result, tmp)
		}
		return
	}

	dfs(root.Left, sum, path, result)
	dfs(root.Right, sum, path, result)

	return
}

func dfs2(root *TreeNode, sum int, path *[]int, result *[][]int) {
	if root == nil {
		return
	}

	sum -= root.Val
	*path = append(*path, root.Val)
	if root.Left == nil && root.Right == nil {
		if sum == 0 {
			tmp := make([]int, len(*path))
			copy(tmp, *path)
			*result = append(*result, tmp)
		}
		*path = (*path)[:len(*path)-1] // 回溯。函数退出的时候，删掉root.Val
		return
	}

	dfs2(root.Left, sum, path, result)
	dfs2(root.Right, sum, path, result)

	*path = (*path)[:len(*path)-1] // 回溯。函数退出的时候，删掉root.Val

	return
}
