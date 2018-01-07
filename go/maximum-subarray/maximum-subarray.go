package maximum_subarray

/*
Find the contiguous subarray within an array (containing at least one number)
which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/

// 求:子串的最大值。也可以找出下标，即哪一段子串
func maxSubArray(nums []int) int {
    if len(nums) == 0 {
        return 0
    }

    result, sum := nums[0], nums[0]

    for i:=1; i<len(nums); i++ {
        if sum >= 0 {
            sum += nums[i]
        } else { // sum已经是负数了，重新开始
            sum = nums[i]
        }

        if sum > result {
            result = sum
        }
    }

    return result
}
