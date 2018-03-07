package roman_to_integer

/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

// "DCXXI" -- > 621   1 + 10 + 10 + 100 + 500
// "XXXIX" -- > 39    10 - 1 + 10 + 10 + 10
func romanToInt(s string) int {
	result := 0

	m := map[byte]int{
		'I': 1,
		'V': 5,
		'X': 10,
		'L': 50,
		'C': 100,
		'D': 500,
		'M': 1000,
	}

	pre := 0
	for i := len(s) - 1; i >= 0; i-- {
		num := m[s[i]]

		if num < pre {
			result -= num
		} else {
			result += num
		}
		pre = num
	}

	return result
}
