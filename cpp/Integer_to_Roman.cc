/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution 
{
public:
    string intToRoman(int num) 
    {
        string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};    
        int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}; 
        
        string result;
        
        // 贪心
        int i = 0;
        while (num > 0)
        {
            while (num >= value[i])
            {
                result += symbol[i];
                num -= value[i];
            }
            i++;
        }
        
        return result;
    }
};
