/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.
*/

class Solution 
{
public:
    int nthUglyNumber(int n)
    {
        int i = 0, j = 0, k = 0;
        vector<int> v{1};
        
        while (v.size() < n)
        {
            int nextUgly = min(min(v[i]*2, v[j]*3), v[k]*5);
            v.push_back(nextUgly);
            if (nextUgly == v[i]*2) i++;
            if (nextUgly == v[j]*3) j++;
            if (nextUgly == v[k]*5) k++;
        }
        
        return v[n-1];
    }

/* Time Limit Exceeded

    int nthUglyNumber(int n) 
    {
        int cnt = 0;
        int i = 1;
        for (; cnt < n; ++i)
        {
            if (isUgly(i)) cnt++;
        }
        
        return i-1;
    }
    
    bool isUgly(int num) 
    {
        if (num <= 0) return false;
        if (num == 1) return true;
        
        while (num % 2 == 0) num /= 2;
        while (num % 3 == 0) num /= 3;
        while (num % 5 == 0) num /= 5;
        
        return num == 1;
    }
*/
};
