/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution 
{
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) 
    {
        sort(S.begin(),S.end());
        vector<vector<int> > result;
        vector<int> path;
        
        dfs(S, result, path, 0);
        
        return result;
    }
private:
    void dfs(vector<int>& S, vector<vector<int> >& result, vector<int>& path, int step)
    {
        result.push_back(path);
        for (int i = step; i < S.size(); i++)
        {
            if (i != step && S[i] == S[i-1])
                continue;
            path.push_back(S[i]);
            dfs(S, result, path, i+1);
            path.pop_back();
        }
    }
};
