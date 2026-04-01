// 74. Search a 2D Matrix

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int low = 0;
        int high = (row * col) - 1;
        while (high >= low)
        {
            int mid = (low + high) / 2;
            int rows = mid / col;
            int cols = mid % col;
            if (matrix[rows][cols] == target)
            {
                return true;
            }
            else if (matrix[rows][cols] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return false;
    }
};

int main(){
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    Solution s;
    cout<<(s.searchMatrix(matrix,target)?"True":"False");
}