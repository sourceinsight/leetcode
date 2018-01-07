/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/

class Solution 
{
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int> > result;
        vector<int> item;
        
        dfs(candidates, target, 0, item, result);
        
        return result;
    }
    
    void dfs(vector<int>& candidates, int gap, int start, vector<int>& item, vector<vector<int> >& result)
    {
        if (gap == 0) // 找个一个解
        {
            result.push_back(item);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++)
        {
            if (candidates[i] > gap)
                return; // 剪枝
                
            item.push_back(candidates[i]);
            dfs(candidates, gap - candidates[i], i, item, result);// 由于可重复选择，那么继续从i
            item.pop_back();
        }
    }
};
