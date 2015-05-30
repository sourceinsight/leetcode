/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/

class Solution 
{
public:
    vector<string> anagrams(vector<string> &strs) 
    {
        vector<string> result;
        map<string, int> mapping; // 每个字符串及其在vector中的位置
        
        for (int i = 0; i < strs.size(); i++)
        {
            string tmp = strs[i];
            std::sort(tmp.begin(), tmp.end());
            
            map<string, int>::iterator it = mapping.find(tmp);
            if (it == mapping.end()) // 没有
            {
                mapping[tmp] = i;
            }
            else // 已有
            {
                if (mapping[tmp] == -1)
                {
                    result.push_back(strs[i]);
                }
                else
                {
                    result.push_back(strs[mapping[tmp]]); // 原来那个
                    mapping[tmp] = -1; // -1（正常都是>=0的）作为一个标识，表示以后直接添加入result中即可
                    result.push_back(strs[i]); // 这个
                }
            }
        }
        
        return result;
    }
};
