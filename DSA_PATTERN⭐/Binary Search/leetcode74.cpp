// 74. Search a 2D Matrix

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int low = 0, high = row - 1;
        int res = -1;
        while (high >= low) {
            int mid = (low + high) / 2;
            if (matrix[mid][0] <= target) {
                low = mid + 1;
                res = mid;
            } else {
                high = mid - 1;
            }
        }
        if(res == -1) return false;
        int lows = 0;
        int highs = col - 1;
        while (highs >= lows) {
            int mid = (lows + highs) / 2;
            if (matrix[res][mid] == target) {
                return true;
            } else if (matrix[res][mid] > target) {
                highs = mid - 1;
            } else {
                lows = mid + 1;
            }
        }
        return false;
    }
};

int main(){
    vector<vector<int>> v= {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    Solution s;
    cout<<(s.searchMatrix(v,target)?"True":"False");
}