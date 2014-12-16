/*
Determine whether an integer is a palindrome. Do this without extra space.
*/
class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        if (x < 0) 
            return false;
        
        int d = 1;
        while (x / d >= 10)
            d *= 10;  // 直接到最高位数
        
        while (x > 0)
        {
            int high = x / d;  // 最高位
            int low = x % 10; // 最低位
            
            if (high != low)
                return false;
            
            x = x % d / 10; // 去掉最高位 和 最低位
            d /= 100; 
        }
        
        return true;
    }
};
