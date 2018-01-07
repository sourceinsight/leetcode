/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Related problem: Reverse Words in a String II
*/

class Solution 
{
public:
    void rotate(int nums[], int n, int k) 
    {
        if (k <= 0)
            return;
            
        k %= n; // don't forget this
            
        _reverse(nums, n-k, n-1);
        _reverse(nums, 0, n-k-1);
        _reverse(nums, 0, n-1);
    }
    
    void _reverse(int num[], int left, int right)
    {
        int tmp;
        while (left < right)
        {
            tmp = num[left];
            num[left++] = num[right];
            num[right--] = tmp;
        }
    }
};
