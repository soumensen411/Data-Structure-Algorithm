#include <bits/stdc++.h>
using namespace std;
void inputOutput()
{
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif
}
void selectionSort(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[min])
            {
                min = j;
            }
        }
        swap(v[i], v[min]);
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
    vector<int> v = {18, -2, 18, 999, 21, 0, -37, 4, 4, 5, 7, 7};
    cout << "Before Sorting: \n";
    display(v);
    selectionSort(v);
    cout << "\nAfter Sorting: \n";
    display(v);
    return 0;
}
