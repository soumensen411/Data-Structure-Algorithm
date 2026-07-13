/*
   _____                                 
  / ___/____  __  ______ ___  ___  ____  
  \__ \/ __ \/ / / / __ `__ \/ _ \/ __ \ 
 ___/ / /_/ / /_/ / / / / / /  __/ / / / 
/____/\____/\__,_/_/ /_/ /_/\___/_/ /_/  
                                         
*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int l = 0;
    int r = l + 1;
    int cnt = 0;
    int ans = 1;
    while (r < n)
    {
        int diff = 0;
        diff = a[r] - a[l];
        if (diff <= 5)
        {
            cnt = r - l + 1;
            r++;
            ans = max(cnt, ans);
        }
        else if (diff > 5)
        {
            l++;
            r++;
        }
    }
    cout << ans;
}
int main()
{
    solve();
    return 0;
}