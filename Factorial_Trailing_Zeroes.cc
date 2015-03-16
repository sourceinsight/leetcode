/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

class Solution 
{
public:
    // 只要查5的个数就可以了。有足够的偶数和5结合成为10
    // 仅为5的倍数，贡献1个；为25的倍数，贡献2个；.....
    //  |_N/5_|+|_N/25_|+|_N/5^3_|+... 
    // 1~n之间5的倍数+1~n之间25的倍数+...
    int trailingZeroes(int n) 
    {
        int result = 0;
        while (n)
        {
            result += n / 5; 
            n /= 5;
        }
        
        return result;
    }
};
