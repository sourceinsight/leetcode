/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?
*/
class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        while (num && !(num & 0b11))
        {
            num >>= 2;
        }

        return num == 1;
    }
};
