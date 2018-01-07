/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

class Solution 
{
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) 
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
        
        int pre = -1; // (a1 ≤ a2 ≤ … ≤ ak)  =号的情况需排除
        for (int i = start; i < candidates.size(); i++)
        {
            if (candidates[i] == pre)
                continue;

            if (candidates[i] > gap)
                return; // 剪枝
                
            pre = candidates[i];
                
            item.push_back(candidates[i]);
            dfs(candidates, gap - candidates[i], i+1, item, result);// 由于不重复选择，那么下一个继续i+1
            item.pop_back();
        }
    }
};
