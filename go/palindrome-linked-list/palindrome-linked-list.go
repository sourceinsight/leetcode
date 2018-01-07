package palindrome_linked_list

/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/

type ListNode struct {
    Val  int
    Next *ListNode
}

// 问题：判断是否是回文链表
func isPalindrome(head *ListNode) bool {
    if head == nil {
        return true
    }

    // 放到数组里，然后判断数组是否是回文
    s := make([]int, 0)
    for ; head != nil; head = head.Next {
        s = append(s, head.Val)
    }

    left, right := 0, len(s)-1
    for left < right {
        if s[left] != s[right] {
            return false
        }
        left++
        right--
    }

    return true
}
