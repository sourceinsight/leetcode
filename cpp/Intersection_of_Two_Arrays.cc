/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/

class Solution
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> result;

        set<int> tmp;
        for (const auto& i : nums1)
        {
            tmp.insert(i);
        }

        for (const auto& i : nums2)
        {
            if (tmp.count(i))
            {
                result.push_back(i);
                tmp.erase(i);
            }
        }

        return result;
    }
};
