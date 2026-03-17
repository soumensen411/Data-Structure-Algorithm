// 1011. Capacity To Ship Packages Within D Days

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculateDays(vector<int> weights, int n, int cap)
    {
        int load = 0;
        int days = 1;
        for (int i = 0; i < n; i++)
        {
            load += weights[i];
            if (load > cap)
            {
                days++;
                load = weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int n = weights.size();
        int ans;
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        for (auto i : weights)
        {
            high += i;
        }
        while (high >= low)
        {
            int mid = (high + low) / 2;
            int day = calculateDays(weights, n, mid);
            if (day <= days)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    Solution s;
    cout << s.shipWithinDays(weights, days);
}