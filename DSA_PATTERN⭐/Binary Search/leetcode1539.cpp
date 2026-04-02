// 1539. Kth Missing Positive Number
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &a, int k)
    {
        int max_val = *max_element(a.begin(), a.end());
        int n = a.size() - 1, i = 0, num = 1, missingCount = 0;
        while (true)
        {
            if (i <= n && a[i] == num)
                i++;
            else
            {
                missingCount++;
                if (missingCount == k)
                    return num;
            }
            num++;
        }
    }
};

int main()
{
    vector<int> v = {2, 3, 4, 7, 11};
    int k = 5;
    Solution s;
    cout << s.findKthPositive(v, k);
}