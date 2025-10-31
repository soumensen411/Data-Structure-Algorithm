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

// Given a 1-indexed sorted array of integers numbers and a target sum target, find two numbers that add up to target.
void two_sum(int arr[], int target, int size)
{
    int left = 0, right = size - 1;

    while (left < right)
    {
        int curr_sum = arr[left] + arr[right];
        if (curr_sum == target)
        {
            cout << "left : " << left + 1 << " right : " << right + 1 << endl;
            return;
        }
        else if (curr_sum < target)
            left++;
        else
            right--;
    }
    cout << "No solution\n";
}

// Given a sorted array nums, remove duplicates in-place such that each unique element appears only once. Return the new length of the array, and the first length elements should contain the unique elements in sorted order. Do not use extra space.

int remove_duplicate(int arr[], int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    int write = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[write - 1])
        {
            arr[write] = arr[i];
            write++;
        }
    }
    return write;
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    two_sum(arr, target, n);

    int new_length = remove_duplicate(arr, n);
    cout << "New Length: " << new_length << endl;
    for (int i = 0; i < new_length; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    optimize();
    solve();
    return 0;
}
