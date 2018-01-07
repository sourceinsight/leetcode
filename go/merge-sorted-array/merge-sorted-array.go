package merge_sorted_array

/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

func merge(nums1 []int, m int, nums2 []int, n int)  {
    i, j, index := 0, 0, 0
    tmp := make([]int, m+n)

    for i<m && j <n {
        if nums1[i] <= nums2[j] {
            tmp[index] = nums1[i]
            i++
        } else {
            tmp[index] = nums2[j]
            j++
        }
        index++
    }

    for i < m {
        tmp[index] = nums1[i]
        i++
        index++
    }
    for j < n {
        tmp[index] = nums2[j]
        j++
        index++
    }

    copy(nums1, tmp)
}