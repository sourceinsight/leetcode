package minimum_moves_to_equal_array_elements

/*
Given a non-empty integer array of size n, find the minimum number of moves required to
make all array elements equal, where a move is incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
*/

// n -1 个数+1，相当于1个数-1

func minMoves(nums []int) int {
	sum, min := 0, nums[0]

	for _, n := range nums {
		sum += n
		if n < min {
			min = n
		}
	}

	return sum - min*len(nums)
}
