package hamming_distance

import (
	"reflect"
	"testing"
)

func TestHammingDistance(t *testing.T) {
	tt := []struct {
		name   string
		x      int
		y      int
		expect int
	}{
		{
			"如题",
			1, // 0 0 0 1
			4, // 0 1 0 0
			2,
		},
		{
			"",
			1,  // 0 0 0 1
			12, // 1 1 0 0
			3,
		},
	}
	for _, tc := range tt {
		t.Run(tc.name, func(t *testing.T) {
			if got := hammingDistance(tc.x, tc.y); !reflect.DeepEqual(got, tc.expect) {
				t.Fatalf("hammingDistance(%v, %v) got %v, expect %v", tc.x, tc.y, got, tc.expect)
			}
		})
	}
}
