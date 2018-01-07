package two_sum

import "sort" // twoSum2

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

// map即哈希表，遍历，每个元素到map中找一下target-v，有即返回，没有则放在map中
func twoSum(nums []int, target int) []int {
	m := make(map[int]int, len(nums)) // num->index
	for i, v := range nums {
		if _, ok := m[target-v]; ok {
			return []int{m[target-v], i} // 注意先后
		}
		m[v] = i
	}
	return nil
}

// 前提是没有重复的元素，否则两个相同元素的位置会覆盖成一个
// 先排序，然后首尾向中间靠拢
func twoSum2(srcNums []int, target int) []int {
	nums := make([]int, len(srcNums))
	copy(nums, srcNums) // 为了不改变原slice，因为要排序
	m := make(map[int]int, len(nums))
	for i, v := range nums {
		m[v] = i
	}
	sort.Ints(nums)
	left, right := 0, len(nums)-1

	for left < right {
		if nums[left]+nums[right] < target {
			left++
		} else if nums[left]+nums[right] > target {
			right--
		} else {
			return []int{m[nums[left]], m[nums[right]]}
		}
	}

	return nil
}
