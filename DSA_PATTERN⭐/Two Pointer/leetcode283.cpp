// 283. Move Zeroes

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int right = 0;
        while (right < nums.size()) {
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};

int main(){
    vector<int> v= {1,0,3,0,12};
    Solution s;
    s.moveZeroes(v);
    for(auto i : v){
        cout<<i<<" ";
    }
}