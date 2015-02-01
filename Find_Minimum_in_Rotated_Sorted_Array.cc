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
        
        while (left < right)
        {
            mid = (left + right) / 2;
            if (num[mid] > num[right])
            {
                left = mid + 1; // mid不可能为最小了，所以+1
            }
            else if (num[mid] < num[right])
            {
                right = mid; // mid不能-1,因为mid可能是那个最小值
            }
        }
        
        return num[left]; // 注意是left,而不是mid,因为只有一个元素时mid没有赋值。
    }
};
