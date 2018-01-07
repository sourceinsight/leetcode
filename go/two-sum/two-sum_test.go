package two_sum

import (
	"reflect"
	"testing"
)

func TestTwoSum(t *testing.T) {
	tt := []struct {
		name   string
		nums   []int
		target int
		expect []int
	}{
		{
			"如题",
			[]int{2, 7, 11, 15},
			9,
			[]int{0, 1},
		},
		{
			"不存在",
			[]int{2, 7, 11, 15},
			3,
			nil,
		},
		{
			"有相同元素",
			[]int{2, 7, 3, 2},
			4,
			[]int{0, 3},
		},
	}
	for _, tc := range tt {
		t.Run(tc.name, func(t *testing.T) {
			if got := twoSum(tc.nums, tc.target); !reflect.DeepEqual(got, tc.expect) {
				t.Fatalf("twoSum(%v, %d) got %v, expect %v", tc.nums, tc.target, got, tc.expect)
			}
			if got := twoSum2(tc.nums, tc.target); !reflect.DeepEqual(got, tc.expect) {
				t.Fatalf("twoSum2(%v, %d) got %v, expect %v", tc.nums, tc.target, got, tc.expect)
			}
		})
	}
}
