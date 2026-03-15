// 268. Missing Number
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums.size() - 1;
        while (high >= low)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == mid)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
    int alternativeSolution(vector<int> nums)
    {

        int n = nums.size();
        int total_sum = (n * (n + 1)) / 2;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        return total_sum - sum;
    }
};

int main()
{
    vector<int> v = {0, 5, 2, 8, 9, 1, 7, 4, 6};
    Solution s;
    cout << "Binary search solution: " << s.missingNumber(v) << endl;
    cout << "Summation Formula Method: " << s.alternativeSolution(v) << endl;
}