/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

class Solution 
{
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> result;
        string str;
        
        generator(result, n, n, str);
        
        return result;
    }
private:
    void generator(vector<string>& result, int left, int right, string str)
    {
        if (left == 0 && right == 0)
        {
            result.push_back(str);
            return;
        }
        
        if (left > 0)
        {
            generator(result, left - 1, right, str + "(");
        }
        if (right > 0 && right > left)
        {
            generator(result, left, right - 1, str + ")");
        }
    }
};
