// Minimum Window Substring

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool find(vector<int> &freqS, vector<int> &freqT)
    {
        for (int i = 0; i < 256; i++)
        {
            if (freqS[i] < freqT[i])
            {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t)
    {
        int low = 0, res = INT_MAX, start = -1;
        vector<int> freq_S(256, 0);
        vector<int> freq_T(256, 0);

        for (int high = 0; high < t.size(); high++)
        {
            freq_T[t[high]]++;
        }
        for (int high = 0; high < s.size(); high++)
        {
            freq_S[s[high]]++;
            while (find(freq_S, freq_T))
            {
                int len = high - low + 1;
                if (res > len)
                {
                    res = len;
                    start = low;
                }
                freq_S[s[low]]--;
                low++;
            }
        }
        if (res == INT_MAX)
            return "";
        return s.substr(start, res);
    }
};

int main()
{
    string s, t;
    s = "ADOBECODEBANC";
    t = "ABC";
    Solution solve;
    cout << solve.minWindow(s, t);
}