// 1047. Remove All Adjacent Duplicates In String

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> str;
        string res;
        for (int i = 0; i < s.size(); i++)
        {
            if (str.empty())
            {
                str.push(s[i]);
                continue;
            }
            if (str.top() == s[i])
            {
                str.pop();
                continue;
            }
            str.push(s[i]);
        }
        while (!str.empty())
        {
            res.push_back(str.top());
            str.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    string s = "abbaca";
    Solution solve;
    cout << solve.removeDuplicates(s);
}