#include <bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int>& v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
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
    freopen("output.txt", "w", stdout);
    vector<int> v = {18 , -2 , 18 , 999 ,21 , 0 , -37 , 4 , 4 , 5 , 7 , 7,};
    bubbleSort(v);
    display(v);
    return 0;
}
