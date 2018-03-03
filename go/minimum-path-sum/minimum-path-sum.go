package minimum_path_sum

/*
Given a m x n grid filled with non-negative numbers,
find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:
[[1,3,1],
 [1,5,1],
 [4,2,1]]
Given the above grid map, return 7. Because the path 1→3→1→1→1 minimizes the sum.
*/

// dp[x][y] = min(dp[x-1][y],dp[x][y-1]) + grid[x][y]
func minPathSum(grid [][]int) int {
	if len(grid) == 0 {
		return 0
	}

	row := len(grid)
	colume := len(grid[0])

	dp := make([][]int, row)
	for i, _ := range dp {
		dp[i] = make([]int, colume)
	}

	dp[0][0] = grid[0][0]

	for i := 1; i < row; i++ {
		dp[i][0] = dp[i-1][0] + grid[i][0]
	}

	for j := 1; j < colume; j++ {
		dp[0][j] = dp[0][j-1] + grid[0][j]
	}

	for i := 1; i < row; i++ {
		for j := 1; j < colume; j++ {
			dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
		}
	}

	return dp[row-1][colume-1]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
