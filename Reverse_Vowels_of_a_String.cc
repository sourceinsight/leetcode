/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".
*/

class Solution
{
public:
    string reverseVowels(string s)
    {
        if (s.size() == 0)
            return s;

        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            if (!isVowel(tolower(s[left])))
                ++left;
            else if (!isVowel(tolower(s[right])))
                --right;
            else
            {
                char tmp = s[left];
                s[left] = s[right];
                s[right] = tmp;
                left++;
                right--;
            }
        }

        return s;
    }

private:
    const string vowels_ = "aeiou";
    bool isVowel(char c)
    {
        return vowels_.find(c) != string::npos;
    }
};
