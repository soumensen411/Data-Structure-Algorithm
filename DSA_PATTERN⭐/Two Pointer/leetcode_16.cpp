// 3sum closest
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
    int threeSumClosest(vector<int> &nums, int target)
    {
        //-4 -1 1 2
        sort(nums.begin(), nums.end());
        int ans;
        int n = nums.size();
        int max = INT_MAX;
        for (int i = 0; i < n - 2; i++)
        {

            int j = i + 1, k = n - 1;

            while (k > j)
            {
                int sum = nums[j] + nums[k] + nums[i];
                if (sum == target)
                {
                    ans = sum;
                    return ans;
                }
                else if (sum < target)
                {
                    int diff = abs(sum - target);
                    if (max > diff)
                    {
                        max = diff;
                        ans = sum;
                    }
                    j++;
                }
                else
                {
                    int diff = abs(sum - target);
                    if (max > diff)
                    {
                        max = diff;
                        ans = sum;
                    }
                    k--;
                }
            }
        }
        return ans;
    }
};
void solve()
{
    vector<int> v = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int target = 1;
    Solution s;
    cout << s.threeSumClosest(v, target);
}
int main()
{
    solve();
    return 0;
}
