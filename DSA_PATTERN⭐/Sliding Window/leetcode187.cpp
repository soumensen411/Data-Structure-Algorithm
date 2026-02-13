// 187. Repeated DNA Sequences

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        unordered_map<string, int> freq;
        int n = s.length();
        vector<string> result;
        if (n < 10)
            return result;
        for (int i = 0; i <= n - 10; i++)
        {
            string sub = s.substr(i, 10);
            freq[sub]++;
            if (freq[sub] == 2)
            {
                result.push_back(sub);
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> result = sol.findRepeatedDnaSequences(s);
    cout << "Repeated DNA Sequences:" << endl;
    for (const string &seq : result)
    {
        cout << "[" << seq << "] ";
    }
    return 0;
}
