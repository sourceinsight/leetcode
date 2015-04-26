/*
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/

class Solution 
{
public:

    int findMin(vector<int> &nums) 
    {
        if (nums.empty())
            return 0;
            
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        int mid;
        
        while (left < right  && nums[left] >= nums[right])
        {
            mid = (left + right) / 2;
            if (nums[mid] > nums[right])
            {
                left = mid + 1; // mid不可能为最小了，所以+1
            }
            else if (nums[mid] < nums[right])
            {
                right = mid; 
            }
            else
            {
                left++;
            }
        }
        
        return nums[left];
    }
};
