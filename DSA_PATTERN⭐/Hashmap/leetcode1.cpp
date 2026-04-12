// Two Sum

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int c = target - nums[i];
            if (mp.find(c) != mp.end())
            {
                return {mp[c], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    vector<int> v = {2,7,11,15};
    int target = 9;
    Solution s;
    vector<int> ans = s.twoSum(v,target);
    for(auto i:ans){
        cout<<i<<" ";
    }
}