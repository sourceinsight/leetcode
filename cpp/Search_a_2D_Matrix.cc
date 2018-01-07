/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

class Solution 
{
public:
/*
    bool searchMatrix(vector<vector<int> >& matrix, int target) 
    {   
        const int row = matrix.size();
        const int col = matrix[0].size();
        if (row <=0 || col <= 0)
            return false;
    
        for (int i = 0; i < row; i++)
        {   
            if (matrix[i][0] == target)
                return true;

            if (i == row-1) // last row 
            {
                for (int j = 0; j < col; j++)
                {
                    if (matrix[i][j] == target)
                        return true;
                }
            }

            if (matrix[i][0] > target)
            {   
                // prev row 
                if (i-1 >= 0)
                {   
                    for (int j = 0; j < col; j++)
                    {   
                        if (matrix[i-1][j] == target)
                            return true;
                    }   
                }   
            }   
        }   

        return false;
    }
*/

    bool searchMatrix(vector<vector<int> >& matrix, int target)
    {
        const int row = matrix.size();
        if (row <= 0)
            return false;

        int index = binarySearchRow(matrix, target);        
        if (index == -1)
            return false;

        return binarySearch(matrix[index], target);
    }

    int binarySearchRow(vector<vector<int> >& m, int target)
    {
        int low = 0;
        int high = m.size() - 1;
        int mid = low + (high - low) / 2;

        while (low <= high)
        {   
            mid = low + (high - low) / 2;
            if (m[mid][0] == target)
                return mid;
            else if (m[mid][0] > target)
                high = mid - 1;
            else 
                //low = mid; // 可导致死循环
                low = mid + 1;  // 最终low的状态是下一行
        }   

        //return mid;
        return low - 1;  
    }
    bool binarySearch(vector<int> line, int target)
    {   
        int low = 0;  
        int high = line.size() - 1;
        int mid = low + (high - low) / 2;

        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (line[mid] == target)
                return true;
            else if (line[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return false;
    }

};
