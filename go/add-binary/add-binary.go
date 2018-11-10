package add_binary

/*
67. 二进制求和

给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字 1 和 0。

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"
*/

func addBinary(a string, b string) string {
	la, lb := len(a), len(b)
	l := la
	if lb > la {
		l = lb
	}
	result := make([]byte, l)

	carry := byte(0)
	for i, j, k := la-1, lb-1, l-1; i >= 0 || j >= 0; i, j, k = i-1, j-1, k-1 {
		num := carry
		if i >= 0 {
			num += a[i] - '0'
		}
		if j >= 0 {
			num += b[j] - '0'
		}

		carry = num / 2
		result[k] = num%2 + '0'
	}

	if carry > 0 {
		result = append([]byte{carry + '0'}, result...)
	}
	return string(result)
}
