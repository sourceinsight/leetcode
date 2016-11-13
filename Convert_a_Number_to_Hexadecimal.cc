/*
Given an integer, write an algorithm to convert it to hexadecimal.
For negative integer, two’s complement method is used.

Note:

1.All letters in hexadecimal (a-f) must be in lowercase.
2.The hexadecimal string must not contain extra leading 0s.
  If the number is zero, it is represented by a single zero character '0';
  otherwise, the first character in the hexadecimal string will not be the zero character.
3.The given number is guaranteed to fit within the range of a 32-bit signed integer.
4. You must not use any method provided by the library which converts/formats the number to hex directly.
Example 1:

Input:
26

Output:
"1a"
Example 2:

Input:
-1

Output:
"ffffffff"
 */

class Solution
{
public:
   string toHex(int num)
   {
       if (num == 0) return "0";
       std::string result;

       int step = 2 * sizeof(num);
       for (int i = 0; i < step; ++i, num >>= 4)
       {
           int n = num & 0xf;
           if (n < 0xa)
           {
               result.push_back('0' + n);
           }
           else
           {
               result.push_back('a' + n - 10);
           }
       }
       reverse(result.begin(), result.end());
       auto pos = result.find_first_not_of('0');
       result = result.substr(pos);

       return result;
   }
};
