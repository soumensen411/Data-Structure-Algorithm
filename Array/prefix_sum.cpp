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
const int size = 1e5 + 5;
int prefix_sum[size];
void solve()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    prefix_sum[0] = arr[0];
    for (int i = 1; i <= n - 1; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }

    int first_indx, last_indx;
    cin >> first_indx >> last_indx;
    int result = 0;
    if(first_indx == 0)
        result = prefix_sum[last_indx];
    else
    result = prefix_sum[last_indx] - prefix_sum[first_indx - 1];
    cout<<result;
}
int main()
{
    inputOutput();
    // for (int i = 0; i < size; i++)
    // {
    //     prefix_sum[i] = 0;
    // }
    solve();
    return 0;
}
