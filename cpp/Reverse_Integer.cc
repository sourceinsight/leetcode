/*
  Reverse digits of an integer.
  Example1: x = 123, return 321
  Example2: x = -123, return -321
*/
class Solution
{
public:
    int reverse(int x)
    {
        // 不用单独处理正负
        //int ret = 0; // 错 无法保存 ret <INT_MIN || ret > INT_MAX
        long long ret = 0;
        while (x) 
        {
            ret = ret * 10 + (x % 10);
            x /= 10;
        }
        
        if (ret < INT_MIN || ret > INT_MAX) 
            return 0;
            
        return ret;
    }
};
