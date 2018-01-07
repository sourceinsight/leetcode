/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

class Solution 
{
public:
    string convert(string s, int nRows) 
    {
        int len = s.size();
        if (nRows <= 1 || nRows >= len)
            return s;
            
        vector<string> lines(nRows);
        int row = 0; // 所在行
        int step = 1; // 行的步长 1或-1 从上到下 从下到上
        // 扫描string s，将字符填到适当的行
        for (int i = 0; i < len; i++)
        {
            if (row == nRows - 1)
                step = -1;
            if (row == 0)
                step = 1;
                
            lines[row].push_back(s[i]);
            row += step;
        }
        
        string ret;
        for (int i = 0; i < nRows; i++)
        {
            ret += lines[i];
        }
        
        return ret;
    }
};
