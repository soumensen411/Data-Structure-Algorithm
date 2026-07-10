#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                int k = j + 1, l = n - 1;
                while (l > k)
                {
                    long long sum = 0;
                    sum += nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if (sum == target)
                    {
                        ans.insert({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                    }
                    else if (sum > target)
                        l--;
                    else
                        k++;
                }
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};

int main()
{
    vector<int> v = {1, 0, -1, 0, -2, 2};
    int target = 0;
    Solution s;
    vector<vector<int>> result = s.fourSum(v, target);

    for (auto &quad : result)
    {
        for (int x : quad)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}