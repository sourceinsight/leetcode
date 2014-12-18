/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";
            
        for (int i = 0; i < strs[0].size(); i++)
        {
            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[0][i] != strs[j][i])
                {
                    //return strs[0].substr(0, i);
                    //return string(strs[0].c_str(), i);
                    return string(strs[0], 0, i);
                }
            }
        }
        
        return strs[0];
    }
};
