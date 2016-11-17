/*
A binary watch has 4 LEDs on the top which represent the hours (0-11),
and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.


For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on,
return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero,
for example "10:2" is not valid, it should be "10:02".
*/

class Solution
{
public:
    vector<string> readBinaryWatch(int num)
    {
        vector<string> result;

        for (int h = 0; h < 12; ++h)
        {
            for (int m = 0; m < 60; ++m)
            {
                if(bits(h) + bits(m) == num)
                {
                    string hour = to_string(h);
                    string minute = m < 10 ? "0" + to_string(m) : to_string(m);
                    result.emplace_back(hour + ":" + minute);
                }
            }
        }
        return result;
    }

private:
    int bits(int n)
    {
        int count = 0;
        while (n > 0)
        {
            n &= (n - 1);
            ++count;
        }
        return count;
    }
};
