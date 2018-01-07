package reverse_string

/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/

func reverseString(s string) string {
	bs := []byte(s)
	left, right := 0, len(bs)-1

	for left < right {
		bs[left], bs[right] = bs[right], bs[left]
		left++
		right--
	}
	return string(bs)
}
