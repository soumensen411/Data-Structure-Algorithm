// 344. Reverse String
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        stack<char> str;
        for (auto c : s)
        {
            str.push(c);
        }
        int i = 0;
        while (!str.empty())
        {
            char c = str.top();
            str.pop();
            s[i] = c;
            i++;
        }
    }
};

int main()
{
    vector<char> s = {'h','e','l','l','o'};
    Solution solve;
    solve.reverseString(s);
    for (char c : s) {
        cout << c << " ";
    }
    
}
