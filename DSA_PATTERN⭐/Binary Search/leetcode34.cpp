// 34. Find First and Last Position of Element in Sorted Array

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int firstPos(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int res = -1;
        while (high >= low)
        {
            int mid = low + high - 1 / 2;
            if (nums[mid] == target)
            {
                res = mid;
                high = mid - 1;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return res;
    }
    int secondPos(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int res = -1;
        while (high >= low)
        {
            int mid = low + high - 1 / 2;
            if (nums[mid] == target)
            {
                res = mid;
                low = mid + 1;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int first = firstPos(nums, target);
        int second = secondPos(nums, target);
        vector<int> v = {first, second};
        return v;
    }
};
int main()
{
    vector<int> v = {5, 7, 7, 8, 8, 10};
    int target = 8;
    Solution s;
    vector<int> res = s.searchRange(v, target);
    for (auto i : res)
        cout << i;
}