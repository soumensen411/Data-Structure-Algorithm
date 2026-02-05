// 724. Find Pivot Index

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int totalsum = 0;
        int n = nums.size();
        for (int num : nums)
        {
            totalsum += num;
        }
        int left = 0;
        for (int i = 0; i < n; i++)
        {
            int right = totalsum - left - nums[i];
            if (left == right)
                return i;
            left += nums[i];
        }
        return -1;
    }
};
int main()
{
    vector<int> v = {1, 7, 3, 6, 5, 6};
    Solution s;
    cout << s.pivotIndex(v);
}