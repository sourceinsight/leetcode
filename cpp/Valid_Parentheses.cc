/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
class Solution 
{
public:
/* 经典的压栈
左括号，直接压栈。右括号，判断栈是否为空和栈顶是否与此右括号匹配，弹出栈顶
元素全部遍历后，栈应为空，判断之。
class Solution 
{
public:
    bool isValid(string s) 
    {
        if (s.length() == 0)
            return true;
            
        stack<char> st;
        
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else
            {
                if (st.empty() || (st.top() == '(' && s[i] != ')') ||
                                    (st.top() == '{' && s[i] != '}') ||
                                    (st.top() == '[' && s[i] != ']'))
                {
                    return false;
                }
                else
                {
                    st.pop();
                }
            }
        }
        
        return st.empty();
    }
};
