/*
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution 
{
public:
    vector<vector<int> > subsets(vector<int> &S) 
    {
        sort(S.begin(), S.end()); // 输出要求有序
        vector<vector<int> > result;
        vector<int> path;
        subsets(S, path, 0, result);
        return result;
    }
private:
    static void subsets(const vector<int>& S, vector<int>& path, int level, vector<vector<int> >& result) 
    {
        if (level == S.size()) 
        {
            result.push_back(path);
            return;
        }
        // 不选 
        subsets(S, path, level + 1, result);
        // 选
        path.push_back(S[level]);
        subsets(S, path, level + 1, result);
        path.pop_back();
    }
};
