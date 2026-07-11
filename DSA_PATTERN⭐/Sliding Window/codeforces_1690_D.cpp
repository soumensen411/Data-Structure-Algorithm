/*

                                        __________  __ __  _____   ____   ____     ______ ____   ____
                                        /  ___/  _ \|  |  \/     \_/ __ \ /    \   /  ___// __ \ /    \
                                        \___ (  <_> )  |  /  Y Y  \  ___/ |   |  \  \___ \\  ___/ |   |  \
                                        /____  >____/|____/|__|_|  /\___  >___|  / /____  >\___  >___|  /
                                            \/                  \/     \/     \/       \/     \/     \/

*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int countW = 0;
        for (int i = 0; i < k; i++)
        {
            if (s[i] == 'W')
                countW++;
        }
        int ans = min(n, countW);
        for (int i = 1; i <= n - k; i++)
        {
            if (s[i - 1] == 'W')
                countW--;
            if (s[i + k - 1] == 'W')
                countW++;
            ans = min(ans, countW);
        }
        cout << ans << endl;
    }
}

int main()
{
    solve();
}