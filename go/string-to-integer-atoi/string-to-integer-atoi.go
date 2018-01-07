package string_to_integer_atoi

import (
    "math"
    "strings"
)

/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself
what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
You are responsible to gather all the input requirements up front.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found.
Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible,
and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number,
which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number,
or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.
If the correct value is out of the range of representable values, INT_MAX (2147483647)
or INT_MIN (-2147483648) is returned.
*/

func myAtoi(str string) int {
    // 去首尾空格
    str = strings.TrimSpace(str)
    if len(str) == 0 {
        return 0
    }

    sign := 1
    switch str[0] {
    case '-':
        sign = -1
        str = str[1:]
    case '+':
        str = str[1:]
    }

    result := 0
    for _, n := range []byte(str) {
        if n < '0' || n > '9' { // 遇到非0~9则终止
            break
        }
        result = result*10 + int(n) - 48 // n - '0'
        if sign*result >= math.MaxInt32 {
            return math.MaxInt32
        } else if sign*result <= math.MinInt32 {
            return math.MinInt32
        }
    }

    return sign * result
}
