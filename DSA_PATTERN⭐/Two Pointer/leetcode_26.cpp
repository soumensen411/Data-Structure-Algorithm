// Remove Duplicates from Sorted Array

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
    int removeDuplicates(vector<int> &nums)
    {
        int left = 0;
        int right = left + 1;
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            if (nums[i] != nums[left])
            {
                nums[left + 1] = nums[i];
                left++;
            }
        }
        return left + 1;
    }
};
void solve()
{
    Solution s;
    vector<int> v = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << s.removeDuplicates(v)<<endl;
    for(auto i:v){
        cout<<i<<" ";
    }
}
int main()
{
    solve();
    return 0;
}
