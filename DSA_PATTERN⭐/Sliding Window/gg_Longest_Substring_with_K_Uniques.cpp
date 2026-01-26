#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestKSubstr(string &s, int k)
    {
        int low = 0, high = 0, res = -1;
        unordered_map<char, int> frequency;
        int len = s.length();
        for (high = 0; high < len; high++)
        {
            frequency[s[high]]++;
            while (frequency.size() > k)
            {
                frequency[s[low]]--;
                if (frequency[s[low]] == 0)
                {
                    frequency.erase(s[low]);
                }
                low++;
            }
            if (frequency.size() == k)
            {
                int dist = high - low + 1;
                res = max(res, dist);
            }
        }
        return res;
    }
};

int main()
{
    string str = "aabacbebebe";
    int k = 3;
    Solution s;
    cout<<s.longestKSubstr(str,k);
}