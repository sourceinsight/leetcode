package reverse_linked_list

import (
    "testing"
    "reflect"
)


func Test_reverseList(t *testing.T) {
    tt := []struct {
        name   string
        input  []int
        expect []int
    }{
        {
            "如题",
            []int{1, 2, 3, 4, 5},
            []int{5, 4, 3, 2, 1},
        },
    }
    for _, tc := range tt {
        t.Run(tc.name, func(t *testing.T) {
            if got := l2s(reverseList(s2l(tc.input))); !reflect.DeepEqual(got, tc.expect) {
                t.Fatalf("reverseList(%v) got %v, expect %v", tc.input, got, tc.expect)
            }
        })
    }
}

// convert *ListNode to []int
func l2s(head *ListNode) []int {
    res := []int{}

    for head != nil {
        res = append(res, head.Val)
        head = head.Next
    }

    return res
}

// convert []int to *ListNode
func s2l(nums []int) *ListNode {
    if len(nums) == 0 {
        return nil
    }

    res := &ListNode{
        Val: nums[0],
    }
    temp := res
    for i := 1; i < len(nums); i++ {
        temp.Next = &ListNode{
            Val: nums[i],
        }
        temp = temp.Next
    }

    return res
}
