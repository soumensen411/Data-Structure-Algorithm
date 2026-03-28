// 367. Valid Perfect Square

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long low = 0;
        long long high = num - 1;
        if (num == 1) {
            return true;
        }
        while (high >= low) {
            long long mid = (low + high) / 2;
            if (mid * mid == num) {
                return true;
            } else if (mid * mid > num) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
};

int main(){
    int num = 16;
    Solution s;
    cout<<(s.isPerfectSquare(num)?"True":"False");
}