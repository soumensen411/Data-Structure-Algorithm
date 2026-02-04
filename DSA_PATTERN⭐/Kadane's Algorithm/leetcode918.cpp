// 918. Maximum Sum Circular Subarray

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int maxSum = nums[0], minSum = nums[0], totalSum = nums[0];
        int bestEnding = nums[0], worstEnding = nums[0], res = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            totalSum += nums[i];
            int v1 = bestEnding + nums[i];
            int v2 = nums[i];
            int v3 = worstEnding + nums[i];
            bestEnding = max(v1, v2);
            worstEnding = min(v3, v2);
            maxSum = max(bestEnding, maxSum);
            minSum = max(worstEnding, minSum);
        }
        res = max(maxSum, totalSum - minSum);
        if (maxSum < 0)
        {
            return maxSum;
        }
        else
        {
            return res;
        }
    }
};

int main(){
    vector<int>v = {1,-2,3,-2};
    Solution s;
    cout<<s.maxSubarraySumCircular(v);
}