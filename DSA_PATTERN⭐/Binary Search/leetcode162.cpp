// 162. Find Peak Element

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;

        while (low < high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] < nums[mid + 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }
};

int main()
{
    vector<int> v = {1, 2, 1, 3, 5, 6, 4};
    Solution s;
    cout<<s.findPeakElement(v);
}