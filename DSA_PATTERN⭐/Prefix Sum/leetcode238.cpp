// 238. Product of Array Except Self

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int k = 0;

        vector<int> ans(nums.size(), 1);
        int prefix = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] = prefix;
            prefix *= nums[i];
        }
        int suffix = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4};
    Solution s;
    vector<int> ans = s.productExceptSelf(v);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}