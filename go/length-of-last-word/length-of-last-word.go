package length_of_last_word

/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/

func lengthOfLastWord(s string) int {
    result := 0
    l := len(s)

    for i:=l-1; i >= 0; i-- {
        if s[i] == ' ' {
            if result == 0 { // "abc  " 排除末尾是' '的情况
                continue
            }
            break
        }
        result++
    }

    return result
}