/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        int first = 0;
        int second = 0;
        int size = nums.size();
        
        while (first < size && second < size)
        {
            while (nums[second] != 0 && second < size) second++; // zero
            while (nums[first] == 0 && first < size) first++; // non-zero
            
            if (first < size  && second < first) // need swap
            {
                int tmp = nums[first];
                nums[first] = nums[second];
                nums[second] = tmp;
                
                second++;
                first++;
            }
            else  // don't need, move first
                first++;
        }
    }
};
