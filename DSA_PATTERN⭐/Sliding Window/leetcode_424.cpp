// Longest Repeating Character Replacement
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMax(vector<int> frequency)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < frequency.size(); i++)
        {
            maxi = max(maxi, frequency[i]);
        }
        return maxi;
    }

    int characterReplacement(string s, int k)
    {
        int low = 0, res = INT_MIN;
        vector<int> frequency(256, 0);
        for (int high = 0; high < s.size(); high++)
        {
            frequency[s[high]]++;
            int len = high - low + 1;
            int maxi = findMax(frequency);
            int difference = len - maxi;
            while (difference > k)
            {
                frequency[s[low]]--;
                low++;
                len = high - low + 1;
                maxi = findMax(frequency);
                difference = len - maxi;
            }
            len = high - low + 1;
            res = max(len, res);
        }
        return res;
    }
};
int main()
{
    string str = "AABABBA";
    int k = 1;
    Solution s;
    cout<<s.characterReplacement(str,k);
}