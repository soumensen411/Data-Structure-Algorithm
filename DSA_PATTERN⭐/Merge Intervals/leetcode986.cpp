// 986. Interval List Intersections

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        vector<vector<int>> res;
        int i = 0, j = 0;
        while (i < firstList.size() && j < secondList.size())
        {
            int start1 = firstList[i][0];
            int end1 = firstList[i][1];
            int start2 = secondList[j][0];
            int end2 = secondList[j][1];
            if (start2 >= start1)
            {
                if (end1 >= start2)
                {
                    int s = max(start1, start2);
                    int e = min(end1, end2);
                    res.push_back({s, e});
                }
            }
            else
            {
                if (end2 >= start1)
                {
                    int s = max(start1, start2);
                    int e = min(end1, end2);
                    res.push_back({s, e});
                }
            }
            if (end2 <= end1)
                j++;

            else
                i++;
        }
        return res;
    }
};

int main()
{
    vector<vector<int>>first = {{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>>second = {{1,5},{8,12},{15,24},{25,26}};
    Solution s;
    vector<vector<int>>res = s.intervalIntersection(first,second);
    for(auto i : res){
        cout<<"["<<i[0]<<","<<i[1]<<"] ";
    }
    
    

}