/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

class Solution 
{
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) 
    {
        vector<vector<int> > result;
        int len = num.size();
        if (len < 4) 
            return result;
        
        sort(num.begin(), num.end());
        
        for (int i = 0; i < len-3; i++)
        {
            if (i > 0 && num[i] == num[i-1]) 
                continue;
                
            for (int j = i+1; j < len-2; j++)
            {
                if (j > i+1 && num[j] == num[j-1])
                    continue;
                    
                int twoSum = target - num[i] - num[j];
                int left = j+1, right = len-1;
                while (left < right)
                {
                    if (num[left] + num[right] > twoSum)
                    {
                        right--;
                    }
                    else if (num[left] + num[right] < twoSum)
                    {
                        left++;
                    }
                    else
                    {
                        result.push_back(vector<int>{num[i], num[j], num[left], num[right]});
                        left++;
                        right--;
                        while (left <right && num[left] == num[left-1]) left++;
                        while (right > left && num[right] == num[right+1]) right--;
                    }
                }
            }
        }
        
        return result;
    }
};
