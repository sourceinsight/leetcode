/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and 
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.
*/

class Solution 
{
public:
    int rob(vector<int>& num) 
    {
        const int n = num.size();
        if (n <= 0)
            return 0;
            
        vector<int> dp(n, 0);
        if (n >= 1)
            dp[0] = num[0];
        if (n >= 2)
            dp[1] = std::max(num[0], num[1]);
        
        for (int i = 2; i < n; i++)
        {
            dp[i] = std::max(dp[i-1], dp[i-2] + num[i]);
        }
        
        return dp[n-1];
    }
};
