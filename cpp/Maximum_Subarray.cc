/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

class Solution 
{
public:
    int maxSubArray(int A[], int n) 
    {
        int sum = A[0], maxSum = A[0];
        
        for (int i = 1; i < n; i++)
        {
            if (sum < 0)
                sum = 0; // 重新开始
                
            sum += A[i];
            maxSum = std::max(maxSum, sum);
        }
        
        return maxSum;
    }
};
