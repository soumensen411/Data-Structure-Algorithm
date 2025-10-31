// Problem: Find the maximum sum of any subarray of size k in an array.

#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    ll window_sum = 0;
    for (int i = 0; i < k; i++)
    {
        window_sum += arr[i];
    }
    ll max_sum = window_sum;
    for (int i = k; i < n; i++)
    {
        window_sum = window_sum + arr[i] - arr[i - k];
        max_sum = max(max_sum, window_sum);
    }
    cout << max_sum;
}
int main()
{
    solve();
    return 0;
}
