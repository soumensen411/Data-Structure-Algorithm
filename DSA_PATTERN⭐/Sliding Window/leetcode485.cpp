// 485. Max Consecutive Ones

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxcount = 0;
        int left = 0;
        int right = 0;
        while (right < nums.size()) {
            if (nums[right] == 1) {
                right++;
            } else {
                maxcount = max(maxcount, right - left);
                right++;
                left = right;
            }
            maxcount = max(maxcount, right - left);
        }
        return maxcount;
    }
};

int main(){
    vector<int> v = {1,1,0,0,0,1,1,1,1};
    Solution s;
    cout<<s.findMaxConsecutiveOnes(v);
}