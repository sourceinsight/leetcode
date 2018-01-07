/*
Given two non-negative numbers num1 and num2 represented as string,
return the sum of num1 and num2.

Note:

1.The length of both num1 and num2 is < 5100.
2.Both num1 and num2 contains only digits 0-9.
3.Both num1 and num2 does not contain any leading zero.
4.You must not use any built-in BigInteger library or convert the inputs to integer directly.
 */
class Solution
{
public:
   string addStrings(string num1, string num2)
   {
       string result;

       for (int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
            i >= 0 || j >= 0 || carry;
            --i, --j, carry /= 10)
       {
           if (i >= 0)
           {
               carry += num1[i] - '0';
           }
           if (j >= 0)
           {
               carry += num2[j] - '0';
           }
           result += to_string(carry % 10);
       }
       reverse(result.begin(), result.end());

       return result;
   }
};
