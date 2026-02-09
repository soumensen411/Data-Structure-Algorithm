// 28. Find the Index of the First Occurrence in a String

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int s = haystack.size();
        int t = needle.size();
        int j = 0;
        int i = 0;
        while (i < s)
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
                if (j == t)
                {
                    return i - t;
                }
            }
            else
            {
                i = i - j + 1;
                j = 0;
            }
        }
        return -1;
    }
};

int main(){
    string haystack = "sadbutsad"; string needle = "sad";
    Solution s;
    cout<<s.strStr(haystack,needle);
}