package palindrome_number

import (
	"reflect"
	"testing"
)

func Test_isPalindromeNumber(t *testing.T) {
	tt := []struct {
		name   string
		input  int
		expect bool
	}{
		{
			"如题",
			12321,
			true,
		},
		{
			"",
			1000021,
			false,
		},
	}
	for _, tc := range tt {
		t.Run(tc.name, func(t *testing.T) {
			if got := isPalindromeNumber(tc.input); !reflect.DeepEqual(got, tc.expect) {
				t.Fatalf("isPalindromeNumber(%v) got %v, expect %v", tc.input, got, tc.expect)
			}
		})
	}
}
