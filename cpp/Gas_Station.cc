/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        const int n = gas.size();
        int ret = 0, total = 0, tmp = 0;
        for (int i = 0; i < n; ++i)
        {
            total += gas[i] - cost[i];
            tmp += gas[i] - cost[i];
            if (tmp < 0) // 当入不敷出时 调整，重新开始
            {
                ret = i + 1;
                tmp = 0;
            }
        }
        return total >= 0 ? ret : -1;
    }
};
