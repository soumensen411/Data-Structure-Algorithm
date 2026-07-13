/*
   _____
  / ___/____  __  ______ ___  ___  ____
  \__ \/ __ \/ / / / __ `__ \/ _ \/ __ \
 ___/ / /_/ / /_/ / / / / / /  __/ / / /
/____/\____/\__,_/_/ /_/ /_/\___/_/ /_/

*/
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

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int i = 0, j = n - 1;
    int sumA = 0, sumB = 0;
    while (j >= i)
    {
        if (sumA <= sumB)
        {
            sumA += v[i];
            i++;
        }
        else
        {
            sumB += v[j];
            j--;
        }
    }
    cout << i << " " << n - j - 1;
}
int main()
{
    solve();
    return 0;
}