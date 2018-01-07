package contains_duplicate

/*
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value
appears at least twice in the array, and it should return false if every element is distinct.
*/

func containsDuplicate(nums []int) bool {
    m := make(map[int]bool, len(nums))

    for _, n := range nums {
        if m[n] {
            return true
        }
        m[n] = true
    }

    return false
}
