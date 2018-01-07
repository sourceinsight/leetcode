package find_all_duplicates_in_an_array

import (
	"reflect"
	"sort"
	"testing"
)

func TestFindDuplicates(t *testing.T) {
	tt := []struct {
		name   string
		nums   []int
		expect []int
	}{
		{
			"如题",
			[]int{4, 3, 2, 7, 8, 2, 3, 1},
			[]int{2, 3},
		},
	}
	for _, tc := range tt {
		t.Run(tc.name, func(t *testing.T) {
			got := findDuplicates(tc.nums)
			sort.Ints(got)
			if !reflect.DeepEqual(got, tc.expect) {
				t.Fatalf("findDuplicates(%v) got %v, expect %v", tc.nums, got, tc.expect)
			}
		})
	}
}
