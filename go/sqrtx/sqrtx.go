package sqrtx

/*
Implement int sqrt(int x).

Compute and return the square root of x.

x is guaranteed to be a non-negative integer.


Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we want to return an integer,
the decimal part will be truncated.
*/

// 二分法
func mySqrt(x int) int {
	low, high := 1, x
	var mid int

	for low <= high {
		mid = (high-low)/2 + low
		if mid*mid == x {
			return mid
		} else if mid*mid < x {
			low = mid + 1
		} else {
			high = mid - 1
		}
	}

	// 到这里一定是low比high大了. 我们要选一个最接近的
	if low*low < x {
		return low
	}
	return high
}

// 牛顿迭代
func mySqrt2(x int) int {
	i := x

	for i*i > x {
		i = (i + x/i) / 2
	}

	return i
}
