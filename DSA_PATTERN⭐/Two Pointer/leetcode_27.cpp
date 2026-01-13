// Remove Element
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
    int removeElement(vector<int> &nums, int val)
    {
        int i = 0;
        int len = nums.size();
        int j = len - 1;
        while (j >= i)
        {
            if (nums[i] == val)
            {
                nums[i] = nums[j];
                j--;
            }
            else
            {
                i++;
            }
        }
        return i;
    }
};
void solve()
{
    vector<int> v = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    Solution s;
    cout << s.removeElement(v, 2);
}
int main()
{
    solve();
    return 0;
}
