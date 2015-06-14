/*
Given an array of integers and an integer k, 
find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] 
and the difference between i and j is at most k.
*/

class Solution 
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_map<int, int> mapping;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mapping.find(nums[i]) != mapping.end() && i - mapping[nums[i]] <= k){
                return true;
            }
            mapping[nums[i]] = i;
        }
        
        return false;
    }
};
