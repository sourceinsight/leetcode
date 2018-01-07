package house_robber

/*
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that
adjacent houses have security system connected and it will automatically
contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house,
determine the maximum amount of money you can rob tonight without alerting the police.
*/

// rob(n) = max(rob(n-2)+money[n], rob(n-1))

// 动态规划 Dynamic Programming

func rob(nums []int) int {
    n := len(nums)
    if n == 0 {
        return 0
    } else if n == 1 {
        return nums[0]
    }

    // 下标为n的房子后，抢了多少钱
    dp := make([]int, n)
    dp[0] = nums[0]
    dp[1] = max(nums[0], nums[1])

    for i := 2; i < n; i++ {
        dp[i] = max(dp[i-2]+num[i], dp[i-1])
    }

    return dp[n-1]
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
