package valid_parentheses

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

// 栈的典型应用
func isValid(s string) bool {
	bs := []byte(s)
	stack := make([]byte, 0, len(bs))

	for _, b := range bs {
		switch b {
		case '(', '{', '[':
			stack = append(stack, b)
		case ')', '}', ']':
			if len(stack) == 0 {
				return false
			}

			if match(stack[len(stack)-1], b) {
				stack = stack[:len(stack)-1]
			} else {
				stack = append(stack, b)
			}
		}
	}

	if len(stack) > 0 {
		return false
	}
	return true
}

func match(a, b byte) bool {
	if a == '(' && b == ')' || a == '{' && b == '}' || a == '[' && b == ']' {
		return true
	}
	return false
}
