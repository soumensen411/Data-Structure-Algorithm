/*
citations = {1, 2, 3, 5, 8, 9}
     6 5 4 3 2 1
     1 2 3 5 8 9
for index = 0, there are 6 papers with atleast 1 citations
for index = 1, there are 5 papers with atleast 2 citations
for index = 2, there are 4 papers with atleast 3 citations
for index = 3, there are 3 papers with atleast 5 citations
for index = 4, there are 2 papers with atleast 8 citations
for index = 5, there are 1 papers with atleast 9 citations

For Binary search, the mid value helps to calculate the number of papers and minimum cites

if papers <= cites, then take interval [start, mid-1] and also update the answer
else, take interval [mid+1, end]
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int low = 0;
        int high = citations.size() - 1;
        int ans = 0;
        while (high >= low)
        {
            int mid = (low + high) / 2;
            int cites = citations[mid];
            int paper = citations.size() - mid;
            if (cites >= paper)
            {
                high = mid - 1;
                ans = paper;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};
int main()
{
    vector<int> v = {0, 1, 3, 5, 6};
    Solution s;
    cout << s.hIndex(v);
}