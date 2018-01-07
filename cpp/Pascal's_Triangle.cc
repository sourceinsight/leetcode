/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution 
{
public:
    vector<vector<int> > generate(int numRows) 
    {
        vector<vector<int> > result;
        if (numRows == 0)
            return result;
            
        result.push_back(vector<int>(1, 1)); // 第一行 1个1
        
        for (int i = 2; i <= numRows; i++)
        {
            const vector<int>& prev = result[i-2]; // 上一行
            
            vector<int> current;
            current.push_back(1); // 开头
            for (int j = 1; j < i - 1; j++) // 中间
            {
                current.push_back(prev[j-1] + prev[j]);
            }
            current.push_back(1); // 结尾
            
            result.push_back(current);
        }
        
        return result;
    }
};
