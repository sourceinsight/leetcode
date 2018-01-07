/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
For example:
Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
*/

class Solution 
{
public:
    int addDigits(int num) 
    {
        while (num >= 10)
        {
            int digit_sum = 0;
            while (num > 0)
            {
                digit_sum += (num % 10);
                num /= 10;
            }
            num = digit_sum;
        }
        
        return num;
    }
};
