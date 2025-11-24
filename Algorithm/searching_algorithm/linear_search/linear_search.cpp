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
bool linear_search(vector<ll> &v, int key)
{
    size_t n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (v[i] == key)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    inputOutput();
    int size;
    ll target;
    cin >> size;
    vector<ll> v(size);
    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }
    cout << "Enter your target: ";
    cin >> target;
    cout << (linear_search(v, target) ? "Found" : "Not Found") << endl;
    return 0;
}
