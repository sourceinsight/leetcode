/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/

class Solution 
{
public:
//进制26 但是从1 到 26 而不是0 到 25
    string convertToTitle(int n) 
    {
        string result;
        while (n > 0)
        {
            char c = (n - 1) % 26 + 'A';
            result.insert(result.begin(), c);
            n = (n - 1) / 26;
        }
        
        return result;
    }
};
