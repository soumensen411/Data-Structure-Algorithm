#include <bits/stdc++.h>
using namespace std;
void inputOutput()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
void merge(vector<int> &v, int s, int mid, int e)
{
    vector<int> tmp;
    int i = s, j = mid + 1;
    while (i <= mid && j <= e)
    {
        if (v[i] <= v[j])
        {
            tmp.push_back(v[i]);
            i++;
        }
        else
        {
            tmp.push_back(v[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        tmp.push_back(v[i]);
        i++;
    }
    while (j <= e)
    {
        tmp.push_back(v[j]);
        j++;
    }
    for (int indx = 0; indx < tmp.size(); indx++)
    {
        v[indx + s] = tmp[indx];
    }
}
void mergesort(vector<int> &v, int s, int e)
{
    if (s < e)
    {
        int mid = s + (e - s) / 2;
        // left
        mergesort(v, s, mid);

        // right
        mergesort(v, mid + 1, e);

        merge(v, s, mid, e);
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "before sort\n";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout<<endl;
    mergesort(v, 0, n-1);
    cout << "after sort\n";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}
int main()
{
    // inputOutput();
    solve();
    return 0;
}
