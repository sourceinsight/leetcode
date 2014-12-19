/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution 
{
public:
    // IV 4; II 2, VI 6
    int romanToInt(string s) 
    {
    	if (s.size() <= 0)
    		return 0;
    		
        int result = 0;
        map<char, int> m; // unordered_map更好
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        result += m[s[0]];
        for (int i = 1; i < s.size(); i++)
        {
          if (m[s[i]] <= m[s[i-1]])
          {
          	result += m[s[i]];
          }
          else
          {
          	result += m[s[i]] - 2 * m[s[i-1]];
          }
        }
      
        return result;
    }

/*
    int m_map(char c)
    {
        int d = 0;
        switch(c)
        {
            case 'I':  
                d = 1;  
                break;  
            case 'V':  
                d = 5;  
                break;  
            case 'X':  
                d = 10;  
                break;  
            case 'L':  
                d = 50;  
                break;  
            case 'C':  
                d = 100;  
                break;  
            case 'D':  
                d = 500;  
                break;  
            case 'M':  
                d = 1000;  
                break;  
        }
        return d;
    }
    int romanToInt(string s) 
    {
    	if (s.size() <= 0)
    		return 0;
    	
    	int result = 0;
    	result += m_map(s[0]);
    	
    	for (int i = 1; i < s.size(); i++)
    	{
          	if (m_map(s[i]) <= m_map(s[i-1]))
          	{
          		result += m_map(s[i]);
          	}
          	else
          	{
          		result += m_map(s[i]) - 2 * m_map(s[i-1]);
          	}
    	}
    	
    	return result;
    }
*/
};
