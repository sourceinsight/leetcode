/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

class Solution 
{
public:
    int longestConsecutive(vector<int> &num) 
    {
        map<int, int> mapping;
        
        for(int i = 0; i < num.size(); i++)
        {
            mapping[num[i]] = i;
        }
        
        int longest = 0;
        for (int i = 0; i < num.size(); i++)
        {
            int cnt = 1;
            
            for(int n = num[i]+1; mapping.find(n) != mapping.end(); n++)
            {
                mapping.erase(mapping.find(n));
                cnt++;
            }
            
            for(int n = num[i]-1; mapping.find(n) != mapping.end(); n--)
            {
                mapping.erase(mapping.find(n));
                cnt++;
            }
            
            if (longest < cnt)
                longest = cnt;
                
            if(mapping.size() == 0)
                break;
        }
        
        return longest;
    }
};
