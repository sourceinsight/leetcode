package ransom_note

/*
Given an arbitrary ransom note string and another string containing letters from all the magazines,
write a function that will return true if the ransom note can be constructed from the magazines ;
otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

// 也可以用长度的为26的数组记录次数
func canConstruct(ransomNote string, magazine string) bool {
	m := make(map[rune]int)
	for _, c := range magazine {
		m[c] += 1
	}

	for _, c := range ransomNote {
		m[c] -= 1
		if m[c] < 0 {
			return false
		}
	}

	return true
}
