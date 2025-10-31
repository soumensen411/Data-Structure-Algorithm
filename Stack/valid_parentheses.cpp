// leetcode problem solve
// https://leetcode.com/problems/valid-parentheses/  description/?envType=problem-list-v2&envId=stack
#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<char> st;
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                cout << "false\n";
                return 0;
            }
            char top = st.top();
            if (s[i] == ')' && top == '(' ||
                s[i] == '}' && top == '{' ||
                s[i] == ']' && top == '[')
            {
                st.pop();
            }
            else
            {
                cout << "false\n";
                return 0;
            }
        }
    }
    if (st.empty())
        cout << "true\n";
    else
        cout << "false\n";
}