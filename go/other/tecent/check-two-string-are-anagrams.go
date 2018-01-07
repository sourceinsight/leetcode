package tencent

// 参考 find-all-anagrams-in-a-string.go

func anagrams(str1, str2 string) bool {
    if len(str1) != len(str2) {
        return false
    }

    chars := [26]int{} // 用map也行
    for _, c := range str1 {
        chars[c-'a']++
    }

    for _, c := range str2 {
        chars[c-'a']--
    }

    if chars == [26]int{} {
        return true
    }
    return false
}


