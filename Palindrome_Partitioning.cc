/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/

class Solution 
{
public:
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string> > result; 
        vector<string> item;
        
        dfs(s, 0, item, result);
        
        return result;
    }

    void dfs(string& s, int begin, vector<string>& item, vector<vector<string> >& result)
    {
        if (begin == s.size())
        {
            result.push_back(item);
            return;
        }
        for (int i = begin; i < s.size(); i++)
        {
            if (isPalindrome(s, begin, i))
            {
                item.push_back(s.substr(begin, i-begin+1));
                dfs(s, i+1, item, result);
                item.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int begin, int end)
    {
        while (begin < end)
        {
            if (s[begin++] != s[end--])
                return false;
        }
        return true;
    }
};
