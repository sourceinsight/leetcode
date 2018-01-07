/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/

class Solution
{
public:
    string reverseString(string s)
    {
        if (s.size() == 0)
            return s;

        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }

        return s;
    }
};
