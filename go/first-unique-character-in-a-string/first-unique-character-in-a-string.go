package first_unique_character_in_a_string

/*
Given a string, find the first non-repeating character in it and
return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

func firstUniqChar(s string) int {
	rec := make([]rune, 26)
	for _, c := range s {
		rec[c-'a']++
	}

	for i, c := range s {
		if rec[c-'a'] == 1 {
			return i
		}
	}

	return -1
}

func firstUniqChar2(s string) int {
	m := make(map[rune]int, len(s))
	for _, c := range s {
		m[c] += 1
	}

	for i, c := range s {
		if m[c] == 1 {
			return i
		}
	}

	return -1
}
