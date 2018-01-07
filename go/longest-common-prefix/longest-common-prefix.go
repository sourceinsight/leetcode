package longest_common_prefix

/*
Write a function to find the longest common prefix string amongst an array of strings.
*/


// 或者,先找出最短的str
func longestCommonPrefix(strs []string) string {
    if len(strs) == 0 {
        return ""
    }

    prefix := make([]byte, 0, len(strs[0]))
    s := []byte(strs[0])
    for i, c := range s {
        for j := 1; j < len(strs); j++ {
                goto exit
            }
        }
        prefix = append(prefix, c)
    }

exit:
    return string(prefix)
}
