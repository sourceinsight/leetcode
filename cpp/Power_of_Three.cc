/*
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?
*/
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        for (; n > 1; n /= 3)
        {
            if (n % 3 != 0) return false;
        }

        return n == 1;
    }
};
