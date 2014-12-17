/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

class Solution 
{
public:
    int removeElement(int A[], int n, int elem) 
    {
        int num = 0;
        for(int i = 0; i < n-num; i++)
        {
            if (A[i] == elem)
            {
                A[i] = A[n-1-num]; // 把最后的元素放到这个'坑'
                num++;
                i--;
            }
        }
        return n-num;
    }
    /*更简单点的
    int removeElement(int A[], int n, int elem) 
    {
        int index = 0;
        for (int i = 0; i < n; ++i) 
        {
            if (A[i] != elem) 
            {
                A[index++] = A[i];
            }
        }
        return index;
    }
    */
};
