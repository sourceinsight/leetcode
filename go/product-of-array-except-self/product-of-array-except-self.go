package product_of_array_except_self

/*
Given an array of n integers where n > 1,
nums, return an array output such that output[i] is equal to
the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity?
(Note: The output array does not count as extra space for
the purpose of space complexity analysis.)
*/

// TODO Time Limit Exceeded???
func productExceptSelf(nums []int) []int {
    length := len(nums)

    // 左侧乘积，右侧乘积
    left, right := make([]int, length), make([]int, length)
    left[0], right[length-1] = 1, 1

    for i := 1; i < length; i++ {
        left[i] = left[i-1] * nums[i-1]
        right[length-i-1] = right[length-i] * nums[length-i]
    }

    result := make([]int, length)
    for i, _ := range nums {
        result[i] = left[i] * right[i]
    }

    return result
}
