// 875. Koko Eating Bananas

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long fun(vector<int> a, long long len, long long speed)
    {
        long long hour = 0;
        for (int i = 0; i < len; i++)
        {
            hour = hour + a[i] / speed;
            if (a[i] % speed != 0)
            {
                hour++;
            }
        }
        return hour;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        long long n = piles.size();
        long long low = 1;
        long long res = -1;
        long long high = *max_element(piles.begin(), piles.end());
        while (high >= low)
        {
            long long guess = (low + high) / 2;
            long long hour = fun(piles, n, guess);
            if (hour > h)
            {
                low = guess + 1;
            }
            else
            {
                res = guess;
                high = guess - 1;
            }
        }
        return res;
    }
};
int main()
{
    vector<int> v = {3, 6, 7, 11};
    int h = 8;
    Solution s;
    cout << s.minEatingSpeed(v, h);
}