/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

class Solution 
{
public:
    int minPathSum(vector<vector<int> >& grid) 
    {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
            
        const int row = grid.size(), col = grid[0].size();
        vector<vector<int> >  dp(row, vector<int>(col));
     
        dp[0][0] = grid[0][0];
        for (int i = 1; i < col; i++)
        {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        for (int j = 1; j < row; j++)
        {
            dp[j][0] = dp[j-1][0] + grid[j][0];
        }
        
        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                dp[i][j] = (dp[i-1][j] < dp[i][j-1] ? dp[i-1][j] : dp[i][j-1]) + grid[i][j];
            }
        }
        
        return dp[row-1][col-1];
    }
};
