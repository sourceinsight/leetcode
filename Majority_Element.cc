/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

class Solution 
{
public:
/*
每两个不同的，则一块删除。最后剩下就是所求的。
可扩展到n/k的情况，每k个不同的一块删除。
*/
    int majorityElement(vector<int> &num) 
    {
        if (num.size() == 0)
            return 0;

        int result = num[0];
        int cnt = 1;
        for (int i = 1; i < num.size(); i++)
        {
            if (cnt == 0)
            {
                result = num[i];
                cnt = 1;
            }
            else
            {
                if (result == num[i])
                    cnt++;
                else
                    cnt--;
            }
        }
        
        return result;
    }
};
