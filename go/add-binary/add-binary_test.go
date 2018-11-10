package add_binary

import (
	"testing"
)

func TestAddBinary(t *testing.T) {
	tt := []struct {
		name   string
		a      string
		b      string
		expect string
	}{
		{
			"如题",
			"11",
			"1",
			"100",
		},
		{
			"如题",
			"1010",
			"1011",
			"10101",
		},
	}
	for _, tc := range tt {
		t.Run(tc.name, func(t *testing.T) {
			if got := addBinary(tc.a, tc.b); got != tc.expect {
				t.Fatalf("addBinary(%v, %v) got %v, expect %v", tc.a, tc.b, got, tc.expect)
			}
		})
	}
}
