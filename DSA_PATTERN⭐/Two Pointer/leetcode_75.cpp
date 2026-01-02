// Sort Colors
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
    void sortColors(vector<int> &nums)
    {
        int zero = 0;
        int one = 0;
        int two = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                zero++;
            else if (nums[i] == 1)
                one++;
            else if (nums[i] == 2)
                two++;
        }
        for (int i = 0; i < zero; i++)
        {
            nums[i] = 0;
        }
        for (int j = zero; j < zero + one; j++)
        {
            nums[j] = 1;
        }
        for (int k = (one + zero); k < one + zero + two; k++)
        {
            nums[k] = 2;
        }
        for (auto i : nums)
        {
            cout << i << ",";
        }
    }
};
int main()
{
    vector<int> v = {2, 0, 2, 1, 1, 0};
    Solution s;
    s.sortColors(v);
    return 0;
}
