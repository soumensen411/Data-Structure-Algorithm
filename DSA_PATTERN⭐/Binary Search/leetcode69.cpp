// 69. Sqrt(x)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        int low = 0;
        int high = x;
        int ans;
        while (high >= low)
        {
            long long int mid = (low + high) / 2;
            long long mulmid = mid * mid;
            if (mulmid == x)
            {
                return mid;
            }
            else if (mulmid > x)
            {
                high = mid - 1;
            }
            else
            {
                ans = mid;
                low = mid + 1;
            }
        }
        return floor(ans);
    }
};

int main()
{
    int x = 2147395599;
    Solution s;
    cout << s.mySqrt(x);
}