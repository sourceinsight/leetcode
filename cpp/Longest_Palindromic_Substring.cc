/*
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

class Solution 
{
public:
    string findPalindrome(string s, int left, int right)
    {
        const int len = s.size();
        while (left >= 0 && right <= len-1 && s[left] == s[right]) 
        {   
            left--;
            right++;
        }   
        return s.substr(left+1, right-left-1);
    }
    
    string longestPalindrome(string s)  
    {
        const int len = s.size();
        if (len <= 1)  
            return s;
    
        string longest;
        string str;
    
        for (int i = 0; i < len-1; ++i) 
        {   
            str = findPalindrome(s, i, i); 
            if (str.size() > longest.size())
                longest = str;
    
            str = findPalindrome(s, i, i+1);
            if (str.size() > longest.size())
                longest = str;
        }   
    
        return longest; 
    }
};
