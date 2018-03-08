package valid_anagram

/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	// Unicode字符
	arr1 := []rune(s)
	arr2 := []rune(t)

	m := make(map[rune]int, len(arr1))
	for i := range arr1 {
		m[arr1[i]]++
		m[arr2[i]]--
	}

	for _, n := range m {
		if n != 0 {
			return false
		}
	}

	return true
}
