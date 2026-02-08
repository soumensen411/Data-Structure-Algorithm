// 1749. Maximum Absolute Sum of Any Subarray

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        int maxSum = INT_MIN, minSum = INT_MAX;
        int bestEnding = 0, worstEnding = 0;
        int res = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            int v1 = bestEnding + nums[i];
            int v2 = nums[i];
            int v3 = worstEnding + nums[i];
            bestEnding = max(v1, v2);
            worstEnding = min(v2, v3);
            maxSum = max(maxSum, bestEnding);
            minSum = min(minSum, worstEnding);
            res = max(abs(maxSum), abs(minSum));
        }
        return res;
    }
};
int main()
{
    vector<int> v = {2, -5, 1, -4, 3, -2};
    Solution s;
    cout << s.maxAbsoluteSum(v);
}