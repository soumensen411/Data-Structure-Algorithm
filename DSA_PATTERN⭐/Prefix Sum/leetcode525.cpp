// 525. Contiguous Array

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        int zero = 0, one = 0;
        unordered_map<int, int> f;
        f[0] = -1;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                zero++;
            }
            else
            {
                one++;
            }
            int diff = one - zero;
            if (diff == 0)
            {
                res = max(res, i + 1);
                continue;
            }
            if (f.find(diff) == f.end())
            {
                f[diff] = i;
            }
            else
            {
                int indx = f[diff];
                int len = i - indx;
                res = max(res, len);
            }
        }
        return res;
    }
};

int main()
{
    vector<int> v = {0, 1, 1, 1, 1, 1, 0, 0, 0};
    Solution s;
    cout << s.findMaxLength(v);
}