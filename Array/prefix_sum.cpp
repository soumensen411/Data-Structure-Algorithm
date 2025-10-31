#include <bits/stdc++.h>
using namespace std;
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
    solve();
    return 0;
}
