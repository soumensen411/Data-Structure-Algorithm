#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string text;
    cin >> text;
    int len = text.length();
    bool flag = false;
    for (int i = 0; i < len / 2; i++)
    {
        if (text[i] != text[len - i - 1])
        {
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        cout << "Palindrome\n";
    }
    else
    {
        cout << "Not Palindrome\n";
    }
}
int main()
{
    solve();
    return 0;
}
