/*
Given a string, find the first non-repeating character in it and return it's index.
If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters
*/

class Solution
{
public:
    int firstUniqChar(string s)
    {
        map<char, int> mapping;

        for (auto& c : s)
        {
            mapping[c]++;
        }
        for (int i = 0; i < s.size(); ++i)
        {
            if (mapping[s[i]] == 1)
                return i;
        }
        return -1;
    }
};
