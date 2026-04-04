// Time Complexity : O(logN)

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int low = 0, high = arr.size() - 1;
        while (high >= low)
        {
            int mid = (low + high) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low + k;
    }
};
int main()
{
    vector<int> v = {2, 3, 4, 7, 11};
    int k = 5;
    Solution s;
    cout << s.findKthPositive(v, k);
}