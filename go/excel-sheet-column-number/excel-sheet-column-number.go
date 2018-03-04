package excel_sheet_column_number

/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
*/

func titleToNumber(s string) int {
	num := 0
	for _, c := range s {
		n := int(c - 'A' + 1) // rune -> int
		num = num*26 + n
	}
	return num
}
