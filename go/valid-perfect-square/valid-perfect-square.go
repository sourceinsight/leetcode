package valid_perfect_square

/*
Given a positive integer num, write a function which returns True
if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False
*/

// 最笨的方法：直接从1循环到n，判断即可。不推荐

// 二分法
func isPerfectSquare(num int) bool {
	low, high := 1, num
	var mid int

	for low <= high {
		mid = (high-low)/2 + low
		if mid*mid == num {
			return true
		} else if mid*mid < num {
			low = mid + 1
		} else {
			high = mid - 1
		}
	}

	return false
}

// 牛顿迭代 https://www.zhihu.com/question/41881138
func isPerfectSquare2(num int) bool {
	x := num
	for x*x > num {
		x = (x + num/x) / 2
	}

	return x*x == num
}
