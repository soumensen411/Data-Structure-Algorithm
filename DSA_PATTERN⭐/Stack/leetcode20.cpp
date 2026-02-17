// 20. Valid Parentheses

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> str;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                str.push(s[i]);
            else
            {
                if (str.empty())
                {
                    return false;
                }
                if (s[i] == ')' && str.top() == '(' || s[i] == '}' && str.top() == '{' || s[i] == ']' && str.top() == '[')
                {
                    str.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        return str.empty();
    }
};

int main()
{
    string s;
    s = "()[]{}";
    Solution solve;
    cout << (solve.isValid(s) ? "True" : "False");
}