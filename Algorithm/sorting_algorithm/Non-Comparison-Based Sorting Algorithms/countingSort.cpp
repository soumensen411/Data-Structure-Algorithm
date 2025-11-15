#include <bits/stdc++.h>
using namespace std;
void countingSort(vector<int> &arr)
{
    int n = arr.size();
    int max = INT_MIN;
    // find max value
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    // count frequency
    vector<int> count_arr(max + 1, 0);
    for (int i = 0; i < n; i++)
    {
        count_arr[arr[i]]++;
    }

    // prefix sum
    for (int i = 1; i <= max; i++)
    {
        count_arr[i] += count_arr[i - 1];
    }

    // build output array
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        ans[count_arr[arr[i]] - 1] = arr[i];
        count_arr[arr[i]]--;
    }
    arr = ans;
}

void display(vector<int> &v)
{

    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

int main()
{
    freopen("output.txt", "w", stdout);
    vector<int> arr = {0, 10, 5, 3, 2, 1, 4, 100, 200, 150};

    cout << "Before Sorting : " << endl;
    display(arr);
    countingSort(arr);
    cout << "After Sorting : " << endl;
    display(arr);
}