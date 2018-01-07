package remove_duplicates_from_sorted_arraylongest_common_prefix

/*
Given a sorted array, remove the duplicates in-place
such that each element appear only once and return the new length.

Do not allocate extra space for another array,
you must do this by modifying the input array in-place with O(1) extra memory.

Example:

Given nums = [1,1,2],

Your function should return length = 2, with the first t
*/

// 原地去重
func removeDuplicates(nums []int) int {
    if len(nums) == 0 {
        return 0
    }

    index := 0 // 新slice下标
    for i := 1; i < len(nums); i++ {
        if nums[i] != nums[index] {
            index++
            nums[index] = nums[i]
        }
    }

    index++
    nums = nums[:index]
    return index
}
