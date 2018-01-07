/*
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
*/

class Solution 
{
public:
    int hammingWeight(uint32_t n) 
    {
        int cnt = 0;
        for (int i = 0; i < sizeof(n)*8; i++)
        {
            if ((n >> i) & 0x01)
                cnt++;
        }
        
        return cnt;
    }

    // n & (n-1)的作用：将n的二进制数中的低位的1改为0
    int hammingWeight2(uint32_t n)
    {
        int cnt = 0;
        while (n != 0)
        {
            n &= (n - 1);
            cnt++;
        }

        return cnt;
    }
};
