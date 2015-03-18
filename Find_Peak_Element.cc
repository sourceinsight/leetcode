/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.
*/

class Solution 
{
public:
    int findPeakElement(const vector<int> &num) 
    {
        // 找驼峰。走到i-1这个位置，那么之前肯定没有返回，也就比左边的大。只需要比右边大即可
        for (int i = 1; i < num.size(); i++)
        {
            if (num[i-1] > num[i])
                return i-1;
        }
        
        return num.size() - 1;
    }
};
