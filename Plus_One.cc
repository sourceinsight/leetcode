/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

class Solution 
{
public:
    vector<int> plusOne(vector<int> &digits) 
    {
        typedef vector<int>::reverse_iterator r_iter;
        int carry = 0;
        
        r_iter it = digits.rbegin();
        *it += 1;
        for (r_iter it = digits.rbegin(); it != digits.rend(); it++)
        {
            *it += carry;
            if (*it == 10)
            {
                carry = 1;
                *it %= 10;
            }
            else
            {
                carry = 0;
            }
        }
        
        if (carry == 1)
            digits.insert(digits.begin(), 1);
            
        return digits;
    }
};
