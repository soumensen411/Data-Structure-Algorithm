// 152. Maximum Product Subarray

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxEnding = nums[0], minEnding = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int v1 = nums[i];
            int v2 = maxEnding * nums[i];
            int v3 = minEnding * nums[i];
            maxEnding = max(v1,max(v2,v3));
            minEnding = min(v1,min(v2,v3));
            ans = max(maxEnding,max(ans,minEnding));
        }
        return ans;
    }
};

int main(){
    vector<int> v = {-2,3,-4};
    Solution s;
    cout<<s.maxProduct(v);
}