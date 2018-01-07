package find_all_anagrams_in_a_string

/*
Given a string s and a non-empty string p,
find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of
both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

// 描述：给定字符串S和P，找出S中所有和P字母构成相同（变位词）的子串，返回下标

// 简单粗暴的方法
func findAnagrams(s string, p string) []int {
    result := []int{}

    if len(s) ==0 || len(p) == 0 || len(s) < len(p) {
        return result
    }

    chars := [26]int{}
    for _, c := range p {
        chars[c-'a']++
    }
    length := len(p)

    for i := 0; i < len(s)-length+1; i++ {
        window := [26]int{}
        // 从i开始的length个
        for j := i; j < i+length; j++ {
            window[s[j]-'a']++
        }
        if window == chars {  // 数组可以直接比较，slice要用reflect.DeepEqual
            result = append(result, i)
        }
    }

    return result
}
