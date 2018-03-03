package sort_colors

/*
Given an array with n objects colored red, white or blue,
sort them so that objects of the same color are adjacent,
with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red,
white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.
*/

// 1 0 0 2 1 2
func sortColors(nums []int) {
	left := 0 // 0后面的1的位置  001122  left=2 right=3
	right := len(nums) - 1 // 2前面1的位置
	index := 0

	for index <= right {
		if nums[index] == 0 {
			swap(nums, index, left)
			index++
			left++
		} else if nums[index] == 1 {
			index++
		} else {
			swap(nums, index, right)
			right--
		}
	}
}

func swap(nums []int, i, j int) {
	nums[i], nums[j] = nums[j], nums[i]
}