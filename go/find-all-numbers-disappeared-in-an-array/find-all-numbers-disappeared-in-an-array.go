package find_all_numbers_disappeared_in_an_array

/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array),
some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime?
You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/

func findDisappearedNumbers(nums []int) []int {
    for i := 0; i < len(nums); i++ {
        for nums[i] != nums[nums[i]-1] { // nums[i]-1是它该在的位置
            nums[i], nums[nums[i]-1] = nums[nums[i]-1], nums[i]
        }
    }

    result := make([]int, 0, len(nums))
    for i, n := range nums {
        if n != i+1 {
            result = append(result, i+1)
        }
    }

    return result
}
