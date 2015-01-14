/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) 
    {
        int len = num.size();
        if (len < 3)
            return 0;
        
        sort(num.begin(), num.end());    
        int result = num[0] + num[1] + num[2];
        for (int i = 0; i < len-2; i++)
        {
            int left = i + 1, right = len - 1;
            while (left < right)
            {
                int tmp = num[i] + num[left] + num[right];
                if (tmp < target)
                {
                    left++;
                }
                else if (tmp > target)
                {
                    right--;
                }
                else
                {
                    return target;
                }
                
                if (abs(tmp - target) < abs(result - target))
                    result = tmp;
            }
        }
        
        return result;
    }
};
