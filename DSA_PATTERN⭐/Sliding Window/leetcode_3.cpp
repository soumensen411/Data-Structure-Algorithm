// Longest Substring Without Repeating Characters
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int low = 0, res = 0;
        unordered_map<char, int> frequency;
        for (int high = 0; high < s.size(); high++)
        {
            frequency[s[high]]++;
            int k = high - low + 1;
            while (frequency.size() < k)
            {
                frequency[s[low]]--;
                if (frequency[s[low]] == 0)
                    frequency.erase(s[low]);
                low++;
                k = high - low + 1;
            }
            int dist = high - low + 1;
            res = max(res, dist);
        }
        return res;
    }
    
};

int main()
{
    string str = "abcabcbb";
    Solution s;
    cout << s.lengthOfLongestSubstring(str);
}