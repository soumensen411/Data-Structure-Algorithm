// 383. Ransom Note

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool fun(unordered_map<char, int> have, unordered_map<char, int> need)
    {
        for (auto i : need)
        {
            char c = i.first;
            int fneed = i.second;
            int fhave = have[c];
            if (fhave < fneed)
            {
                return false;
            }
        }
        return true;
    }

    bool canConstruct(string ransomNote, string magazine)
    {
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        unordered_map<char, int> have;
        unordered_map<char, int> need;
        for (int i = 0; i < ransomNote.size(); i++)
        {
            need[ransomNote[i]]++;
        }
        for (int i = 0; i < magazine.size(); i++)
        {
            have[magazine[i]]++;
        }
        return fun(have, need);
    }
};

int main()
{
    string s1 = "aa";
    string s2 = "aab";
    Solution s;
    cout << (s.canConstruct(s1, s2) ? "True" : "False");
}