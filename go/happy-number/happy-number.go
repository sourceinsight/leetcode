package happy_number

/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process:
Starting with any positive integer, replace the number by the sum of the squares of its digits,
and repeat the process until the number equals 1 (where it will stay),
or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

func isHappy(n int) bool {
	m := make(map[int]struct{})
	m[n] = struct{}{}

	for {
		n = calc(n)
		if n == 1 {
			return true
		}

		// 如果在一个没有1的循环中，那么第二次循环的时候一定已经在里面了
		if _, ok := m[n]; ok {
			return false
		}
		m[n] = struct{}{}
	}

	return false
}

func calc(n int) int {
	result := 0
	for n != 0 {
		result += (n % 10) * (n % 10)
		n /= 10
	}
	return result
}
