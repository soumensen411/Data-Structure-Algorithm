// Minimum Size Subarray Sum

#include <bits/stdc++.h>
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl '\n'
#define ll long long
#define yes "YES\n"
#define no "NO\n"
using namespace std;
void inputOutput()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int high = 0, low = 0, n = nums.size();
        int sum = 0, ans = INT_MAX;
        bool flag = false;
        while (n > high)
        {
            sum += nums[high];
            while (sum >= target)
            {
                flag = true;
                int len = high - low + 1;
                ans = min(ans, len);
                sum = sum - nums[low];
                low++;
            }
            high++;
        }
        if (!flag)
        {
            return 0;
        }
        else
            return ans;
    }
};
void solve()
{
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    Solution s;
    cout << s.minSubArrayLen(target, nums);
}
int main()
{
    inputOutput();
    solve();
    return 0;
}
