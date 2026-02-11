// 57. Insert Interval
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {

        vector<vector<int>> temp;
        bool insert = false;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (insert == false && intervals[i][0] > newInterval[0])
            {
                temp.push_back(newInterval);
                insert = true;
            }
            temp.push_back(intervals[i]);
        }
        if (!insert)
            temp.push_back(newInterval);
        int start1 = temp[0][0];
        int end1 = temp[0][1];
        vector<vector<int>> res;
        for (int i = 0; i < temp.size(); i++)
        {
            int start2 = temp[i][0];
            int end2 = temp[i][1];
            if (end1 >= start2)
            {
                start1 = start1;
                end1 = max(end1, end2);
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
    vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval = {4, 8};
    Solution s;
    vector<vector<int>> result = s.insert(intervals, newInterval);
    for (const auto &interval : result)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
}