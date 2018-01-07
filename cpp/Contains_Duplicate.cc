/*
Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in the array, 
and it should return false if every element is distinct.
*/

class Solution 
{
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_map<int, int> mapping;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (mapping.find(nums[i]) != mapping.end())
                return true;
                
            mapping[nums[i]] = i; 
        }
        
        return false;
    }
/*
    bool containsDuplicate(vector<int>& nums) 
    {
        if (nums.size() <= 0)
            return false;
            
        unordered_map<int, int> mapping;
        
        for (int i = 0; i < nums.size(); i++)
        {
            mapping[nums[i]] = i; 
        }
        
        if (mapping.size() < nums.size())
        {
            return true;
        }
        
        return false;
    }
*/
};
