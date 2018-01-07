class Solution 
{
public:
    void merge(int A[], int m, int B[], int n) 
    {
        int ia = m - 1, ib = n -1, icur = m + n - 1;
        while (ia >= 0 && ib >= 0)
        {
            // 从后向前！
            if (B[ib] >= A[ia])
            {
                A[icur--] = B[ib--];
            }
            else
            {
                A[icur--] = A[ia--];
            }
        }
        
        while (ib >= 0)
        {
            A[icur--] = B[ib--];
        }
    }
};
