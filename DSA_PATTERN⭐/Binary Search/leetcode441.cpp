#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int arrangeCoins(int n)
    {
        if (n == 1)
            return 1;
        long low = 1, high = n;
        while (high >= low)
        {
            long mid = (low + high) / 2;
            long cn = mid * (mid + 1) / 2;
            if (cn == n)
            {
                return mid;
            }
            else if (cn > n)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return high;
    }
};

int main()
{
    int n = 5;
    Solution s;
    cout << s.arrangeCoins(n);
}