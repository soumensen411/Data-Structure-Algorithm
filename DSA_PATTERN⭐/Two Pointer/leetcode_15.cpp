// 3Sum

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
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        // -4 -1 -1 0 1 2
        sort(nums.begin(), nums.end());
        int len = nums.size();

        vector<vector<int>> ans;
        for (int i = 0; i < len - 2; i++)
        {
            int left = i + 1, right = len - 1;

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum == -nums[i])
                {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right + 1])
                    {
                        right--;
                    }
                }
                else if (sum > -nums[i])
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return ans;
    }
};

void solve()
{
    vector<int> v = {-1, 0, 1, 2, -1, -4};
    Solution s;
    vector<vector<int>> result = s.threeSum(v);
    for (auto &triplet : result)
    {
        cout << "[" << triplet[0] << " " << triplet[1] << " " << triplet[2] << "]" << endl;
    }
}
int main()
{
    solve();
    return 0;
}
