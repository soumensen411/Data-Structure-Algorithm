// 409. Longest Palindrome

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> mp;
        int res = 0;
        bool odd = false;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        for (auto i : mp)
        {
            if (i.second % 2 == 0)
                res += i.second;
            else
                odd = true;
        }
        if (!odd)
            return res;
        else
        {
            for (auto i : mp)
            {
                if (i.second % 2 != 0)
                    res += i.second - 1;
            }
        }
        return res + 1;
    }
};

int main()
{
    string s = "abccccdd";
    Solution solve;
    cout << solve.longestPalindrome(s);
}