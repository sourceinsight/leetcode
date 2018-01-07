/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

class Solution 
{
public:
    int divide(int dividend, int divisor) 
    {
        assert(divisor != 0);
        bool flag = true;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) 
        {
            flag = false;
        }
        
        // 当 dividend = INT_MIN 时， -dividend 会溢出，所以用 long long
        long long left = abs((long long)dividend);
        long long right = abs((long long)divisor);
        // 当 dividend = INT_MIN 时， divisor = -1 时，结果会溢出，所以用 long long
        long long result = 0;
        
        while (left >= right)
        {
            long long tmpDivisor = right;
            for (int i = 0; (tmpDivisor << i) <= left; i++)
            {
                left -= (tmpDivisor << i);
                result += (1 << i);
            }
        }
        
        if (flag == false)
            result *= -1;
        if (result > INT_MAX)
            return INT_MAX;
            
        return result;
    }
};
