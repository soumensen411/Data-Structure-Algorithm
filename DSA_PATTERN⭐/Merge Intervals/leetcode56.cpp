// 56. Merge Intervals

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int start1 = intervals[0][0];
        int end1 = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++)
        {
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];
            if (end1 >= start2)
            {
                start1 = start1;
                end1 = max(end1, end2);
                continue;
            }
            else
            {
                res.push_back({start1, end1});
                start1 = start2;
                end1 = end2;
            }
        }
        res.push_back({start1, end1});
        return res;
    }
};

int main()
{

    vector<vector<int>> v = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    Solution s;
    vector<vector<int>> result = s.merge(v);

    // Print the result
    cout << "Merged intervals: [";
    for (const auto &interval : result)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "]";
    }
    cout << "]" << endl;
}