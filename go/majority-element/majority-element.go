package majority_element

/*
Given an array of size n, find the majority element.
The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

/*
问题：求众数

每两个不同的，则一块删除。最后剩下就是所求的。
可扩展到n/k的情况，每k个不同的一块删除。
*/

func majorityElement(nums []int) int {
	result := nums[0]
	cnt := 1

	for i := 1; i < len(nums); i++ {
		if cnt == 0 {
			result = nums[i] // 换下一个有可能
			cnt = 1          // 重置计数
		} else if nums[i] == result {
			cnt++
		} else {
			cnt--
		}
	}

	return result
}
