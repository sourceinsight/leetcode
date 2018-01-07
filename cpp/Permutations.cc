/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

class Solution 
{
public:
    /*
    1 2 3
    1 3 2
    2 1 3
    2 3 1
    3 1 2
    3 2 1
    */
    vector<vector<int> > permute(vector<int>& num) 
    {
        vector<vector<int> > result;
        vector<bool> available(num.size(), true);
        
        vector<int> item;
        dfs(num, available, item, result);
        
        return result;
    }
    
    void dfs(const vector<int>& num, vector<bool>& available, vector<int>& item, vector<vector<int> >& result)
    {
        if (item.size() == num.size())
        {
            result.push_back(item);
            return;
        }
        for (int i = 0; i < num.size(); ++i)
        {
            if (available[i])
            {
                available[i] = false;
                item.push_back(num[i]);
                dfs(num, available, item, result);
                item.pop_back();
                available[i] = true;
            }
        }
    }
};
