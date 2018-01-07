package fizz_buzz

import (
	"reflect"
	"testing"
)

func TestFizzBuzz(t *testing.T) {
	tt := []struct {
		name   string
		n      int
		expect []string
	}{
		{
			"如题",
			15,
			[]string{
				"1",
				"2",
				"Fizz",
				"4",
				"Buzz",
				"Fizz",
				"7",
				"8",
				"Fizz",
				"Buzz",
				"11",
				"Fizz",
				"13",
				"14",
				"FizzBuzz",
			},
		},
	}
	for _, tc := range tt {
		t.Run(tc.name, func(t *testing.T) {
			if got := fizzBuzz(tc.n); !reflect.DeepEqual(got, tc.expect) {
				t.Fatalf("fizzBuzz(%v) got %v, expect %v", tc.n, got, tc.expect)
			}
		})
	}
}
