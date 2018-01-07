package climbing_stairs

/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps.
In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.


Example 1:

Input: 2
Output:  2
Explanation:  There are two ways to climb to the top.

1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output:  3
Explanation:  There are three ways to climb to the top.

1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

// 直观，但超时了。不推荐
func climbStairs(n int) int {
    if n == 1 {
        return 1
    } else if n == 2 {
        return 2
    }

    return climbStairs(n) + climbStairs(n-1)
}

// 利用了中间计算结果
func climbStairs2(n int) int {
    if n == 1 {
        return 1
    }

    ways := make([]int, n+1)
    ways[0], ways[1] = 1, 1

    for i := 2; i <= n; i++ {
        ways[i] = ways[i-1] + ways[i-2]
    }

    return ways[n]
}

