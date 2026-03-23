// 1351. Count Negative Numbers in a Sorted Matrix

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] < 0)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main()
{
    vector<vector<int>> v = { {4, 3, 2, -1},
                              {3, 2, 1, -1},
                              {1, 1, -1, -2},
                              {-1, -1, -2, -3}};
    Solution s;
    cout<<s.countNegatives(v);
}