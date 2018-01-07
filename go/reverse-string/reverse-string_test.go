package reverse_string

import (
	"testing"
)

func TestReverseString(t *testing.T) {
	tt := []struct {
		name   string
		input  string
		expect string
	}{
		{
			"如题",
			"hello",
			"olleh",
		},
	}
	for _, tc := range tt {
		t.Run(tc.name, func(t *testing.T) {
			if got := reverseString(tc.input); got != tc.expect {
				t.Fatalf("reverseString(%v) got %v, expect %v", tc.input, got, tc.expect)
			}
		})
	}
}
