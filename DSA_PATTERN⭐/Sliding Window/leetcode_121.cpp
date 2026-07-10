// Best Time to Buy and Sell Stock

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int l = 0;
        int r = 1;
        int maxProfit = 0;
        while (r < prices.size())
        {
            if (prices[r] > prices[l])
            {
                int profit = prices[r] - prices[l];
                maxProfit = max(profit, maxProfit);
            }
            else
            {
                l = r;
            }
            r++;
        }
        return maxProfit;
    }
};

int main()
{
    vector<int> v = {7, 1, 5, 3, 6, 4};
    Solution s;
    cout << s.maxProfit(v);
}