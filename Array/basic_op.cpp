#include <bits/stdc++.h>
using namespace std;
void solve()
{
    // initialize array
    int n = 5;
    int arr[n];

    // insertion into array
    arr[0] = 5;
    arr[1] = 10;
    arr[2] = 30;
    arr[3] = 100;
    arr[4] = 1;

    // traversing into array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // deletion from array

    int pos = 2;
    for (int i = pos; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "After deletion at pos " << pos << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    solve();
    return 0;
}
