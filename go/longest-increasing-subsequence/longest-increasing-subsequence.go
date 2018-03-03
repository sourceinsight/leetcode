package longest_increasing_subsequence

/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4.
Note that there may be more than one LIS combination,
it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/

// TODO 没通过
func lengthOfLIS(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	max := 1
	length := 1
	for i := 1; i < len(nums); i++ {
		if nums[i] > nums[i-1] {
			length++
			if length > max {
				max = length
			}
		} else {
			length = 1
		}
	}

	return max
}