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

class Solution 
{
public:
    int titleToNumber(string s) 
    {
        if (s.size() == 0)
            return 0;
            
        int result = 0;
        for (int i = 0; i < s.size(); i++)
        {
            result = result * 26 + s[i] - 'A' + 1;
        }
        
        return result;
    }
};
