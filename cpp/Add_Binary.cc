/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

class Solution 
{
public:
    string addBinary(string a, string b)
    {
    	string result;
    	
    	int len1 = a.size();
    	int len2 = b.size();
    	int carry = 0;
    	
    	int i = len1 - 1;
    	int j = len2 - 1;
    	
    	for ( ; i >= 0 && j >= 0; i--, j--)
    	{
    		result.push_back((a[i] - '0' + b[j] - '0' + carry) % 2 + '0');
    		carry = (a[i] - '0' + b[j] - '0' + carry) / 2;
    	}
    	
    	if (i > j)
    	{
    		for ( ; i >= 0; i--)
    		{
    			result.push_back((a[i] - '0' + 0 + carry) % 2 + '0');
    			carry = (a[i] - '0' + 0 + carry) / 2;
    		}
    	}
    	else if (i < j)
    	{
    		for ( ; j >= 0; j--)
    		{
    			result.push_back((0 + b[j] - '0' + carry) % 2 + '0');
    			carry = (0 + b[j] - '0' + carry) / 2;
    		}
    	}
    	
    	if (carry == 1)
    		result.push_back('0' + carry);
    		
    	reverse(result.begin(), result.end());
    		
    	return result;
    }
};
