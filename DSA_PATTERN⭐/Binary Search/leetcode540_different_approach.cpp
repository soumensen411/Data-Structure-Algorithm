// O(logn) time complexity

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;
        while (high > low)
        {
            int mid = (low + high) / 2;
            if (mid % 2 == 1)
                mid--;
            if (nums[mid] == nums[mid + 1])
            {
                low = mid + 2;
            }
            else
            {
                high = mid;
            }
        }
        return nums[low];
    }
};

int main()
{
    vector<int> v = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    Solution s;
    cout << s.singleNonDuplicate(v);
}
