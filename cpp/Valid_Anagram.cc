/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
*/

class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
        if (s.size() != t.size())
            return false;
            
        map<char, int> mapping1;
        for (auto c : s)
            mapping1[c]++;
        
        map<char, int> mapping2;
        for (auto c : t)
            mapping2[c]++;
        
        for (auto it1 = mapping1.begin(), it2 = mapping2.begin(); it1 != mapping1.end(); it1++, it2++)
        {
            if (it1->first != it2->first || it1->second != it2->second)
                return false;
        }
        
        return true;
    }
};
