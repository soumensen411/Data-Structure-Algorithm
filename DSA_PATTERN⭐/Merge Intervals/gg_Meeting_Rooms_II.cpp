#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMeetingRooms(vector<int> &start, vector<int> &end)
    {
        // code here
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int i = 0, j = 0, room = 0, res = INT_MIN;

        while (i < start.size() && j < end.size())
        {
            if (start[i] < end[j])
            {
                i++;
                room++;
                res = max(res, room);
            }
            else
            {
                j++;
                room--;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> start = {1, 10, 7};
    vector<int> end = {4, 15, 10};
    Solution s;
    cout << s.minMeetingRooms(start, end);
}