#include <bits/stdc++.h>
void inputOutput()
{
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
}
using namespace std;
void insertionSort(vector<int> &v)
{
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        int key = v[i], ptr = i - 1;
        while (ptr >= 0 && v[ptr] > key)
        {
            v[ptr + 1] = v[ptr];
            ptr = ptr - 1;
        }
        v[ptr + 1] = key;
    }
}
void display(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}
int main()
{
    inputOutput();
    vector<int> v = {-90,120,600,-2,18,999,21,0,-37,4,4,5,7,7};
    cout << "Before Sorting: \n";
    display(v);
    insertionSort(v);
    cout << "\nAfter Sorting: \n";
    display(v);
    return 0;
}