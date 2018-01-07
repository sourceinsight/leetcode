package palindrome_number

/*
Determine whether an integer is a palindrome. Do this without extra space.
*/

// 回文数字，比如12321
func isPalindromeNumber(x int) bool {
	if x < 0 {
		return false
	}

	div := 1 // 数量级
	for n := x; n >= 10; n /= 10 {
		div *= 10
	}

	for x > 0 {
		if x/div != x%10 {
			return false
		}
		x = (x % div) / 10 // 去掉首尾
		div /= 100
	}

	return true
}
