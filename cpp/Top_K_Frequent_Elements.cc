/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        vector<int> result;

        map<int, int> counts;
        for (const auto& i : nums)
        {
            ++counts[i];
        }

        vector<pair<int, int>> tmp;
        for (auto it = counts.begin(); it != counts.end(); ++it)
        {
            tmp.emplace_back(it->second, it->first);
        }
        nth_element(tmp.begin(), tmp.begin() + k - 1, tmp.end(), compareFunc);

        for (int i = 0; i < k; i++)
        {
            result.push_back(tmp[i].second);
        }

        return result;
    }

    static bool compareFunc(const pair<int, int>& lhs, const pair<int, int>& rhs)
    {
        return lhs.first > rhs.first;
    }
};
