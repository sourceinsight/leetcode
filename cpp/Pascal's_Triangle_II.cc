/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution 
{
public:
    // use only O(k) extra space
    vector<int> getRow(int rowIndex) 
    {
        vector<int> result;
        
        for (int i = 0; i <= rowIndex; i++)
        {
            for (int j = i - 1; j > 0; j--)
            {
                result[j] = result[j-1] + result[j]; 
            }
            result.push_back(1);
        }
        
        return result;
    }
    /*
    vector<int> getRow(int rowIndex) 
    {
        if (rowIndex < 0)
            return vector<int>();
        if (rowIndex == 0)
            return vector<int>(1,1);
        
        vector<int> prev = vector<int>(1, 1);
        for (int i = 1; i <= rowIndex; i++)
        {
            vector<int> result;
            result.push_back(1);    
            for (int j = 1; j < i; j++)
            {
                result.push_back(prev[j-1] + prev[j]);
            }
            result.push_back(1);
            
            prev = result;
        }
        
        return prev;
    }
    */
};
