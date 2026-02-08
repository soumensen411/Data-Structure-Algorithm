// 974. Subarray Sums Divisible by K
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int count = 0, sum = 0;
        unordered_map<int, int> frequency;
        frequency[0] = 1;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            int reminder = sum % k;
            if (reminder < 0)
            {
                reminder += k;
            }
            count += frequency[reminder];
            frequency[reminder]++;
        }
        return count;
    }
};

int main()
{
    vector<int> v = {4, 5, 0, -2, -3, 1};
    int k = 5;
    Solution s;
    cout << s.subarraysDivByK(v, k);
}