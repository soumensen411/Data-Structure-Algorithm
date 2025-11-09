#include <bits/stdc++.h>
using namespace std;
int partition(vector<int> &arr, int start, int end)
{
    int pivot = arr[end]; // last element as a pivot
    int index = start - 1;
    for (int i = start; i < end; i++)
    {

        if (arr[i] <= pivot)
        {
            index++;
            swap(arr[index], arr[i]);
        }
    }
    index += 1;
    swap(arr[index], arr[end]); // place pivot as a correct position.
    return index; // return pivot index
}
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);  // left partition -> start to pivot - 1
        quickSort(arr, pivot + 1, high); // left partition -> pivot + 1 to end
    }
}
void display(vector<int> arr)
{
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}
int main()
{
    freopen("output.txt", "w", stdout);
    vector<int> arr =  {-50, -20, 0, 10, 5, 3, 2, 1, 4, 100, 200, 150};
    cout << "Before Sorting : " << endl;
    display(arr);
    quickSort(arr, 0, arr.size() - 1);
    cout << "After Sorting : " << endl;
    display(arr);
}