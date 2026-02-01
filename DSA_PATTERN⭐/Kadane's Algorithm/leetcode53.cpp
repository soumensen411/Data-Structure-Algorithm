// 53. Maximum Subarray

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int bestEnding = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int v1 = bestEnding + nums[i];
            int v2 = nums[i];
            bestEnding = max(v1, v2);
            ans = max(ans, bestEnding);
        }
        return ans;
    }
};

int main()
{
    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution s;
    cout<<s.maxSubArray(v);
}