package excel_sheet_column_number

import (
	"testing"
)

func Test_titleToNumber(t *testing.T) {
	tt := []struct {
		name   string
		s      string
		expect int
	}{
		{
			"如题",
			"A",
			1,
		},
		{
			"",
			"AB",
			28,
		},
	}
	for _, tc := range tt {
		t.Run(tc.name, func(t *testing.T) {
			if got := titleToNumber(tc.s); got != tc.expect {
				t.Fatalf("titleToNumber(%v) got %v, expect %v", tc.s, got, tc.expect)
			}
		})
	}
}
