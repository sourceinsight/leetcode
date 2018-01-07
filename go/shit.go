package golang




func firstUniqChar2(s string) int {
    type meta struct {
        index int
        count int
    }

    m := make(map[rune]meta, len(s))
    for i, c := range s {
        if mt, ok := m[c]; !ok {
            m[c] = meta{i, 1}
        } else {
            m[c] = meta{i, mt.count+1}
        }
        // https://stackoverflow.com/questions/32751537/why-do-i-get-a-cannot-assign-error-when-setting-value-to-a-struct-as-a-value-i
        // https://stackoverflow.com/questions/17438253/access-struct-in-map-without-copying?noredirect=1&lq=1
        //m[c].count++  // 错
        //m[c].index = i
    }

    for _, c := range s {
        if m[c].count == 1 {
            return m[c].index
        }
    }

    return -1
}

func firstUniqChar2_test_map_struct(s string) int {
    type meta struct {
        index int
        count int
    }

    m := make(map[rune]*meta, len(s))
    for i, c := range s {
        if _, ok := m[c]; !ok {
            m[c] = &meta{i, 1}
        } else {
            m[c].count++ // 这就可以
        }
    }

    for _, c := range s {
        if m[c].count == 1 {
            return m[c].index
        }
    }

    return -1
}

