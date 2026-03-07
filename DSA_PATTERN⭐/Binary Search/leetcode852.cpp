// 852. Peak Index in a Mountain Array
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int low = 0;
        int high = arr.size() - 1;
        int res = -1;
        while (high >= low)
        {
            int mid = (low + high) / 2;
            if (arr[mid] < arr[mid+1])
            {
                low =  mid+1;
            }
            else
            {
                res = mid;
                high = mid - 1;
            }
        }
        return res;
    }
};
int main()
{
    vector<int> v = {0, 1, 0};
    Solution s;
    cout<<s.peakIndexInMountainArray(v);
}