/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

class Solution 
{
public:
/*
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int result = INT_MAX;
        
        dfs(triangle, 0, 0, 0, result);
        
        return result;
    }
    void dfs(vector<vector<int> >& triangle, int pathSum, int level, int position, int& result)
    {
        if (level == triangle.size())
        {
            result = std::min(result, pathSum);
            return;
        }
        
        for (int i = position; i <= position+1 && i < triangle[level].size(); i++)
        {
            dfs(triangle, pathSum + triangle[level][i], level+1, i, result);
        }
    }
*/
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        for (int i = triangle.size() - 2; i >= 0; --i)
        {
            for (int j = 0; j < i + 1; ++j)
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
        }

        return triangle[0][0];
    }
};
