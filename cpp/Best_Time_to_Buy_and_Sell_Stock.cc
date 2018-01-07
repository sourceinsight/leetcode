/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

class Solution 
{
public:
    int maxProfit(vector<int> &prices) 
    {
        if (prices.size() == 0)
            return 0;
            
        int max = 0, delta = 0;
        int low = prices[0];
        
        for (int i = 1; i < prices.size(); i++)
        {
            delta = prices[i] - low;
            if (delta <= 0)
                low = prices[i];
            if (delta > max)
                max = delta;
        }
        
        return max;
    }
};
