package longest_substring_without_repeating_characters

/*
3. 无重复字符的最长子串

给定一个字符串，找出不含有重复字符的最长子串的长度。

示例 1:

输入: "abcabcbb"
输出: 3
解释: 无重复字符的最长子串是 "abc"，其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 无重复字符的最长子串是 "b"，其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 无重复字符的最长子串是 "wke"，其长度为 3。
     请注意，答案必须是一个子串，"pwke" 是一个子序列 而不是子串。
*/

// 遍历该字符串，每遍历一个字母时，利用map去找该字母最近一次出现是什么时候，中间这一段便是无重复字符的字符串。
func lengthOfLongestSubstring(s string) int {
	result := 0
	m := make(map[byte]int, len(s)) // 字符-->出现时的索引

	start := 0 // 起始点 当发现出现重复的时候，就调整 起始点
	for i, c := range []byte(s) {
		if index, ok := m[c]; !ok || index < start { // 不存在 或已经在start之前，即是遗留数据
			m[c] = i // 赋值或覆盖
			result = max(i-start+1, result)
		} else { // 存在了
			start = m[c] + 1 // 更新起始点
			m[c] = i         // 覆盖
		}
	}

	return result
}

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}
