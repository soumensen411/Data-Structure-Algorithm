// 560. Subarray Sum Equals K
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int totalsum = 0, res = 0;
        unordered_map<int, int> f;
        f[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            totalsum += nums[i];
            int ques = totalsum - k;
            int freq = f[ques];
            res += freq;
            f[totalsum]++;
        }
        return res;
    }
};

int main()
{
    vector<int> v = {1, 2, 3};
    int k = 3;
    Solution s;
    cout << s.subarraySum(v, k);
}