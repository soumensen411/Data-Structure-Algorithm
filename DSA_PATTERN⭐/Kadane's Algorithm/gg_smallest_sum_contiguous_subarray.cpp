#include <bits/stdc++.h>
using namespace std;
// User function Template for C++

class Solution
{
public:
    int smallestSumSubarray(vector<int> &a)
    {
        // Code here
        int WorstEnding = a[0];
        int res = a[0];
        for (int i = 1; i < a.size(); i++)
        {
            int v1 = WorstEnding + a[i];
            WorstEnding = min(v1, a[i]);
            res = min(WorstEnding, res);
        }
        return res;
    }
};
int main()
{
    vector<int> v = {3, -4, 2, -3, -1, 7, -5};
    Solution s;
    cout << s.smallestSumSubarray(v);
}