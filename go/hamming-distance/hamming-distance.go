package hamming_distance

/*
The Hamming distance between two integers is the number of positions
at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
*/

// 汉明距离，对应位置的不同位的个数
// 异或，然后找到
func hammingDistance(x int, y int) int {
	result := 0

	x ^= y
	for x != 0 {
		result += x & 1
		x >>= 1
	}

	return result
}
