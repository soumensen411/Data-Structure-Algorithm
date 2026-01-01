// Two Sum II - Input Array Is Sorted
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
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> ans;
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right)
        {
            int sum = numbers[left] + numbers[right];
            if (sum == target)
            {
                ans.push_back(left + 1);
                ans.push_back(right + 1);
                return ans;
            }
            if (sum > target)
                right--;
            else
                left++;
        }
        return {-1, -1};
    }
};
void solve()
{
    Solution s;
    vector<int> v = {2, 7, 11, 15};
    vector<int> result = s.twoSum(v, 9);
    cout << result[0] << " " << result[1] << endl;
}
int main()
{
    // inputOutput();
    solve();
    return 0;
}
