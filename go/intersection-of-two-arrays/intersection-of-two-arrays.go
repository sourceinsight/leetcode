package intersection_of_two_arrays

/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/

// 问题描述：求交集

func intersection(nums1 []int, nums2 []int) []int {
	if len(nums1) == 0 || len(nums2) == 0 {
		return []int{}
	}

	// 最好操作副本，没有副作用，此处省略
	sort.Ints(nums1)
	sort.Ints(nums2)

	result := []int{}
	for i, j := 0, 0; i < len(nums1) && j < len(nums2); {
		if nums1[i] < nums2[j] {
			i++
		} else if nums1[i] > nums2[j] {
			j++
		} else {
			if len(result) == 0 || nums1[i] != result[len(result)-1] { // 不重复的才加到结果集中
				result = append(result, nums1[i])
			}
			i++
			j++
		}
	}

	return result
}
