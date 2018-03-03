package move_zeroes

/*
Given an array nums, write a function to move all 0's to the end of it
while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12],
after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

// 原地倒腾，非零的都赋值到前面  操作len(nums)次
func moveZeroes(nums []int) {
	index := 0 // 新的索引
	for _, n := range nums {
		if n != 0 {
			nums[index] = n
			index++
		}
	}

	for j := index; j < len(nums); j++ {
		nums[j] = 0
	}
}

// 原地交换   操作 2*非零个数 次，所以非零很少的情况下才用此法
func moveZeroes(nums []int) {
	index := 0 // 新的非零索引，指向目前第一个零的位置
	for i, n := range nums {
		if n != 0 {
			nums[index], nums[i] = nums[i], nums[index]
			index++
		}
	}
}
