// https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
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
    int maxSubarraySum(vector<int> &arr, int k)
    {
        // code here
        int len = arr.size();
        int low = 0;
        int high = k - 1;
        int sum = 0;
        int ans = 0;
        int new_sum = 0;
        for (int i = low; i <= high; i++)
        {
            sum += arr[i];
        }
        while (high < len)
        {

            ans = max(sum, ans);
            low++;
            high++;
            if (high == len)
                break;
            else
                sum = sum + arr[high];
            sum = sum - arr[low - 1];
        }
        return ans;
    }
};
void solve()
{
    vector<int> v = {100, 200, 300, 400};
    Solution s;
    cout << s.maxSubarraySum(v, 2);
}
int main()
{
    // inputOutput();
    solve();
    return 0;
}
