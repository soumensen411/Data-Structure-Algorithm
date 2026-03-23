// 1422. Maximum Score After Splitting a String

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScore(string s)
    {
        int totalOne = 0;
        int zeroCount = 0;
        int oneCount = 0;
        int bestAns = INT_MIN;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
                totalOne++;
        }
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == '0')
                zeroCount++;
            else
                oneCount++;
            bestAns = max(bestAns, zeroCount + (totalOne - oneCount));
        }
        return bestAns;
    }
};

int main(){
    string str = "011101";
    Solution s;
    cout<<s.maxScore(str);
}