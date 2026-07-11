/*   
                                                        
  __________  __ __  _____   ____   ____     ______ ____   ____  
 /  ___/  _ \|  |  \/     \_/ __ \ /    \   /  ___// __ \ /    \ 
 \___ (  <_> )  |  /  Y Y  \  ___/|   |  \  \___ \\  ___/|   |  \
/____  >____/|____/|__|_|  /\___  >___|  / /____  >\___  >___|  /
     \/                  \/     \/     \/       \/     \/     \/ 

*/

#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int t;
    cin >> t;
    while (t)
    {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        vector<int> b(k);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < k; i++)
        {
            cin >> b[i];
        }
        sort(a.begin(), a.end(), greater<>());
        sort(b.begin(), b.end());
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += a[i];
        }
        int index = 0;
        for (int i = 0; i < k && index < n; i++)
        {
            if (b[i] == 1)
            {
                ans -= a[index];
                index++;
            }
            else
            {
                index += b[i] - 1;
                if (index >= n)
                {
                    break;
                }
                else
                {
                    ans -= a[index++];
                }
            }
        }
        cout << ans << endl;
        t--;
    }
}
int main()
{
    solve();
    return 0;
}