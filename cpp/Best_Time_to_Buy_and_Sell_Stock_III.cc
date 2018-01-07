/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution 
{
public:
    int maxProfit(vector<int> &prices) 
    {
        if (prices.size() <= 1)
            return 0;
            
        const int n = prices.size();
        vector<int> f(n); // 0...i的最大利润
        vector<int> g(n); // i...n-1的最大利润
        
        int min_price = prices[0];
        for (int i = 1; i < n; i++)
        {
            min_price = min(min_price, prices[i]);
            f[i] = max(f[i-1], prices[i] - min_price);
        }
        
        int max_price = prices[n-1];
        for (int i = n-2; i >= 0; i--)
        {
            max_price = max(max_price, prices[i]);
            g[i] = max(g[i+1], max_price - prices[i]);
        }
        
        int max_profit = 0;
        for (int i = 0; i < n; i++)
            max_profit = max(max_profit, f[i] + g[i]);
            
        return max_profit;
    }
};
