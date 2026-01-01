// squares-of-a-sorted-array
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
    vector<int> sortedSquares(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> pos;
        vector<int> neg;
        vector<int> ans(len);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                pos.push_back(nums[i]);
            }
            else
            {
                neg.push_back(nums[i]);
            }
        }
        if (neg.size() == 0)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                nums[i] = nums[i] * nums[i];
            }
            return nums;
        }
        else if (pos.size() == 0)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                neg[i] = neg[i] * neg[i];
            }
            reverse(neg.begin(), neg.end());
            return neg;
        }
        else
        {
            for (int i = 0; i < neg.size(); i++)
            {
                neg[i] = neg[i] * neg[i];
            }
            for (int j = 0; j < pos.size(); j++)
                pos[j] *= pos[j];
            reverse(neg.begin(), neg.end());
            int i = 0, j = 0, id = 0;
            int n = neg.size();
            int m = pos.size();

            while (i < n && j < m)
            {
                if (neg[i] <= pos[j])
                {
                    ans[id++] = neg[i++];
                }
                else
                {
                    ans[id++] = pos[j++];
                }
            }
            while (i < n)
            {
                ans[id++] = neg[i++];
            }
            while (j < m)
            {
                ans[id++] = pos[j++];
            }
        }
        return ans;
    }
};

void solve()
{
    vector<int>v = {-4,-1,0,3,10};
    Solution s;
    vector<int> result = s.sortedSquares(v);
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
}
int main()
{
    solve();
    return 0;
}
