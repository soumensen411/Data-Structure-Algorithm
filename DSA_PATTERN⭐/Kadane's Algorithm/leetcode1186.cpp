// 1186. Maximum Subarray Sum with One Deletion

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximumSum(vector<int> &arr)
    {
        int noDel = arr[0];
        int oneDel = INT_MIN;
        int res = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            int preNoDel = noDel;
            int preOneDel = oneDel;
            noDel = max(arr[i], noDel + arr[i]);
            int v2;
            if (preOneDel == INT_MIN)
            {
                v2 = arr[i];
            }
            else
            {
                v2 = preOneDel + arr[i];
            }
            oneDel = max(v2, preNoDel);
            res = max(res, max(noDel, oneDel));
        }
        return res;
    }
};

int main()
{
    vector<int> v = {1, -2, 0, 3};
    Solution s;
    cout << s.maximumSum(v);
}