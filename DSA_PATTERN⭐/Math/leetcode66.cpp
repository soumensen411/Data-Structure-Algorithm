#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
int main()
{

    vector<int> v = {4, 3, 2, 1};
    Solution s;
    vector<int> ans = s.plusOne(v);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}