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
bool binary_search(vector<ll> &v, ll key)
{
    ll size = v.size();

    int left = 0;
    int right = size - 1;
    while (right >= left)
    {
        ll middle = left + (right - left) / 2;
        if (v[middle] == key)
        {
            return true;
        }
        else if (v[middle] > key)
        {
            right = middle - 1;
        }
        else if (v[middle] < key)
        {
            left = middle + 1;
        }
    }
    return false;
}
int main()
{
    inputOutput();
    int size;
    cin >> size;
    vector<ll> v(size);
    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int target;
    cin >> target;
    cout << (binary_search(v, target) ? "Found" : "Not Found");
    return 0;
}
