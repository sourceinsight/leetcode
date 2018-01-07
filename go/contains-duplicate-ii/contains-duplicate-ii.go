package contains_duplicate_ii

/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array
such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
*/

func containsNearbyDuplicate(nums []int, k int) bool {
    m := make(map[int]int) // 值->索引

    for i, n := range nums {
        if _, ok := m[n]; ok {
            if i - m[n] <= k {
                return true
            }
        }
        m[n] = i // 不是else分支
    }

    return false
}
