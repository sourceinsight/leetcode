/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

class Solution 
{
public:
    int strStr(char *haystack, char *needle) 
    {
        if (haystack == NULL || needle == NULL)
            return -1;
            
        int hLen = strlen(haystack);
        int nLen = strlen(needle);
        
        if (nLen == 0)
            return 0;
            
        if (hLen == 0)
            return -1;
            
        if (hLen < nLen)
            return -1;
            
        int i = 0, j = 0, k = -1;
        for ( ; i < hLen; i++)
        {
            j = 0;
            if (haystack[i] == needle[j] && j < nLen)
            {
                k = i;
                while (haystack[i] == needle[j] && j < nLen)
                {
                    i++;
                    j++;
                }
                
                if (needle[j] == '\0')
                    return k;
                else 
                    i = k;
            }
        }
        
        return -1;
    }
};
