// 153. Find Minimum in Rotated Sorted Array

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while(high>low){
            int mid = (low + high) / 2;
            if(nums[mid]>nums[high]){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return nums[low];
    }
};

int main(){
    // vector<int> v = {3,4,5,6,7,0,1,2};
    vector<int> v = {11,12,13,15,17};
    Solution s;
    cout<<s.findMin(v);
}