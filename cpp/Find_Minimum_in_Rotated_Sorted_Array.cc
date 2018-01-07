/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

class Solution 
{
public:
    int findMin(vector<int> &num) 
    {
        if (num.empty())
            return 0;
            
        int size = num.size();
        int left = 0;
        int right = size - 1;
        int mid;
        
        // 画一下，就知道，最终状态是left与right重合
        while (left < right)
        {
            mid = (left + right) / 2;
            if (num[mid] > num[right])
            {
                left = mid + 1; // mid不可能为最小了，所以+1
            }
            else if (num[mid] < num[right])
            {
                right = mid; 
            }
        }
        
        return num[left]; // 或num[right] 但不是mid，如果用mid，见下面方式
    }

    int findMin_2(vector<int> &num) 
    {
        if (num.empty())
            return 0;
            
        int size = num.size();
        int left = 0;
        int right = size - 1;
        int mid = (left + right) / 2;

        while (left < right)
        {
            mid = (left + right) / 2;
            if (num[mid] > num[right])
            {
                left = mid + 1; // mid不可能为最小了，所以+1
            }
            else if (num[mid] < num[right])
            {
                right = mid;
            }
        }
        mid = (left + right) / 2;
        
        return num[mid]; 
    }
};
