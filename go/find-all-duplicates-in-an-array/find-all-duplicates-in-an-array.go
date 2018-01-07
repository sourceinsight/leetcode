package find_all_duplicates_in_an_array

/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), 
some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/

// 直观的解法。
func findDuplicates(nums []int) []int {
	m := make(map[int]int, len(nums)) // 数字-->出现次数
	var result []int

	for _, n := range nums {
		m[n]++
	}
	for k, v := range m {
		if v == 2 {
			result = append(result, k)
		}
	}

	return result
}
