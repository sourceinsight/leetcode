/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

class Solution 
{
public:
    // 这种方法可以拓展为 every element appears k times except for one
    int singleNumber(int A[], int n) 
    {
        int result = 0;
        int count[32] = {0}; // 保存每个位的次数
        
        for (int bit = 0; bit < 32; bit++)
        {
            for (int index = 0; index < n; index ++)
            {
                if ((A[index] >> bit) & 1)
                {
                    count[bit]++;
                }
            }
            result |= ((count[bit] % 3) << bit); // 拼出the single one
        }
        
        return result;
    }
};
