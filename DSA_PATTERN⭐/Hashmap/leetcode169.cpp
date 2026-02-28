#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        int maxi;
        return max_element(mp.begin(), mp.end(),
                           [](const std::pair<int, int> &p1,
                              const std::pair<int, int> &p2)
                           {
                               return p1.second < p2.second;
                           })
            ->first;
    }
};
int main()
{
    vector<int> v = {2, 2, 1, 1, 1, 2, 2};
    Solution s;
    cout<<s.majorityElement(v);
}