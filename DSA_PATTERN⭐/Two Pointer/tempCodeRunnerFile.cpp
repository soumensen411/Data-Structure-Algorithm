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
    long long countTriplets(int n, long long sum, long long arr[])
    {

        long long count = 0;
        sort(arr, arr + n);

        for (int i = 0; i < n; i++)
        {
            int k = n - 1, j = i + 1;
            while (k > j)
            {
                long long dsum = arr[i] + arr[j] + arr[k];
                if (dsum >= sum)
                    // 1 3 4 5 7
                    k--;
                else if (dsum < sum)
                {
                    count += (k - j);
                    j++;
                }
            }
        }
        return count;
    }
};
void solve()
{
    ll arr[] = {5, 1, 3, 4, 7};
    Solution s;
    cout << s.countTriplets(5, 12, arr);
}
int main()
{
    solve();
    return 0;
}
