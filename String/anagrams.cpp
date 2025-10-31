#include <bits/stdc++.h>
using namespace std;
static string normalization(const string &s)
{
    string new_string;
    for (unsigned char c : s)
    {
        if (isalpha(c))
        {
            new_string += tolower(c);
        }
        else if (isdigit(c))
        {
            new_string += c;
        }
    }
    sort(new_string.begin(), new_string.end());
    return new_string;
}
void solve()
{
    cout << "Enter first string: ";
    string text_1;
    getline(cin, text_1);
    cout << "Enter second string: ";
    string text_2;
    getline(cin, text_2);
    string a = normalization(text_1);
    string b = normalization(text_2);

    if (a == b)
    {
        cout << "Yeap..! It's anagram\n";
    }
    else
    {
        cout << "Nope..!" << endl;
    }
}
int main()
{
    solve();
    return 0;
}
