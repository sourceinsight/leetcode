/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
*/

class Solution 
{
public:
    int atoi(const char *str) 
    {
        int num = 0;
        int sign = 1; // 默认正
        const int n = strlen(str);
        int i = 0;
        
        // 空格处理
        while (str[i] == ' ' && i < n)
            i++;
        
        // 符号处理
        if (str[i] == '+')
        {
            i++;
        }
        else if (str[i] == '-')
        {
            sign = -1;
            i++;
        } // 没有else哦
        
        // 处理数字部分
        for (; i < n; i++)
        {
            if (str[i] < '0' || str[i] > '9')
                break;
            if (num > INT_MAX / 10 || 
                (num == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10))
            {
                return sign == -1 ? INT_MIN : INT_MAX;
            }
            
            num = num * 10 + str[i] - '0'; // 核心
        }
        
        return num * sign;
    }
};
