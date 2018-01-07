/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

class Solution 
{
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> keyboard = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; // 0~9
        vector<string> result;
        string path;
        
        dfs(keyboard, result, digits, path, 0);
        
        return result;
    }
    
    void dfs(vector<string>& keyboard, vector<string>& result, string& digits, string& path, int dIndex)
    {
        if (dIndex == digits.length()) 
        {
            result.push_back(path);
            return;
        }
        int num = digits[dIndex] - '0';
        for (int i = 0; i < keyboard[num].length(); i++) 
        {
            //tmp.append(1, keyboard[num][i]);
            path.push_back(keyboard[num][i]);
            dfs(keyboard, result, digits, path, dIndex + 1);
            path.pop_back();
        }
    }
};
