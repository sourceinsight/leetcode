/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

class Solution 
{
public:
    int lengthOfLastWord(const char *s) 
    {
        if (s == NULL)
            return 0;
            
        const char* p = s;
        while (*p != '\0')
            p++;
        
        p--;
        while (*p == ' ' && p >= s)
            p--;
        const char* end = p;
        
        while (isalpha(*p) && p >= s)
            p--;
        const char* begin = p + 1;
        
        return end - begin + 1;
    }
};
