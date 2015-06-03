/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
*/

class Solution 
{
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        bool rArray[matrix.size()] = {false};
        bool cArray[matrix[0].size()] = {false};
        for (int row = 0; row < matrix.size(); row++)
        {
            for (int col = 0; col < matrix[row].size(); col++)
            {
                if (matrix[row][col] == 0)
                {
                    rArray[row] = true;
                    cArray[col] = true;
                }
            }
        }
        
        for (int row = 0; row < matrix.size(); row++)
        {
            for (int col = 0; col < matrix[0].size(); col++)
            {
                if (rArray[row] || cArray[col])
                    matrix[row][col] = 0;               
            }
        }
    }
};
