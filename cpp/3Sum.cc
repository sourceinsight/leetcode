/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

class Solution 
{
public:
    vector<vector<int> > threeSum(vector<int> &num) 
    {
        vector<vector<int> > result;
        // 先排序是必须的
        sort(num.begin(), num.end());
        
        int len = num.size();
        
        for (int i = 0; i < len-2; i++)
        {
            // 避免重复
            if (i>0 && num[i] == num[i-1])
                continue;
                
            int twoSum = 0 - num[i];
            int left = i + 1, right = len - 1;
            while (left < right)
            {
                if (num[left] + num[right] < twoSum)
                {
                    left++;
                }
                else if (num[left] + num[right] > twoSum)
                {
                    right--;
                }
                else
                {
                    result.push_back(vector<int>{num[i], num[left], num[right]});
                    left++;
                    right--;
                    // 避免重复
                    while (left < right && num[left] == num[left-1]) left++;
                    while (left < right && num[right] == num[right+1]) right--;
                }
            }
        }

        return result;
    }
};
