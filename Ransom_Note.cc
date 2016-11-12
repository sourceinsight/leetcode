/*
Given  an  arbitrary  ransom  note  string  and  another  string  containing  letters from  all  the  magazines, 
write  a  function  that  will  return  true  if  the  ransom   note  can  be  constructed  from  the  magazines ;  
otherwise,  it  will  return  false.   

Each  letter  in  the  magazine  string  can  only  be  used  once  in  your  ransom  note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> counts(26);
        int letters = 0;
        for (const auto& c : ransomNote)
        {
            if (counts[c-'a']++ == 0)
            {
                ++letters;
            }
        }

        for (const auto& c : magazine)
        {
            if (--counts[c-'a'] == 0 && --letters == 0)
            {
                // 如果满足了，那么可以提早退出循环
                break;
            }
        }
        return letters == 0;
    }
};
