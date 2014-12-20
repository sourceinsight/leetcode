/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

class Solution 
{
public:
/* 暴力。超时了。思路直接
    vector<int> twoSum(vector<int> &numbers, int target) 
    {
        vector<int> result;
        
        if (numbers.size() <= 1)
            return result;
        
        for (int i = 0; i < numbers.size()-1; i++)
        {
            for (int j = i+1; j < numbers.size(); j++)
            {
                if (numbers[i] + numbers[j] == target)
                {
                    result.push_back(i+1);
                    result.push_back(j+1);
                    return result;
                }
            }
        }

        return result;
    }
*/
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        
        if (numbers.size() < 2)
            return vector<int>();
        
        map<int, int> mapping; // unordered_map更好
        vector<int> result;
        
        for (int i = 0; i < numbers.size(); i++)
        {
            mapping[numbers[i]] = i; // 存储每个数对应的下标
        }
        
        for (int i = 0; i < numbers.size(); i++)
        {
            const int gap = target - numbers[i];
            
            if (mapping.find(gap) != mapping.end() && mapping[gap] > i)
            {
                result.push_back(i + 1);
                result.push_back(mapping[gap] + 1);
                break;
            }
        }
        
        return result;
    }
};
