package missing_number

/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
find the one that is missing from the array.

Example 1

Input: [3,0,1]
Output: 2
Example 2

Input: [9,6,4,2,3,5,7,0,1]
Output: 8

Note:
Your algorithm should run in linear runtime complexity.
Could you implement it using only constant extra space complexity?
*/

func missingNumber(nums []int) int {
	n := len(nums)
	sum := n * (n + 1) / 2

	for _, num := range nums {
		sum -= num
	}

	return sum
}

/*
0 ^ 0 = 0
b ^ b = 0
0 ^ a = a
a ^ b ^ b = a

只有一个数，没有 异或过自己
*/
func missingNumber2(nums []int) int {
	result := 0

	for i, n := range nums {
		result ^= i ^ n
	}

	return result ^ len(nums) // 去掉最大的那个，剩下的就是要找的
}

// 放在该在的位置 比如3就放在下标为3的位置  错误的原因：内存不够，所以先append一个元素，扩展够
// TODO 还未完成， 还挺难控制。。。
func missingNumber3(nums []int) int {
	const E = -1
	nums = append(nums, E) // 新加的这个-1放在最后
	changed := false

	for i, n := range nums {
		if n != i {
			if n == len(nums)-1 && !changed { // 最后的位置是E，直接覆盖掉它，不要交换
				nums[n] = n
				changed = true
			} else {
				nums[i], nums[n] = nums[n], n
			}
		}
	}

	for i, n := range nums {
		if n != i {
			return i
		}
	}

	return -1
}
