// 33. Search in Rotated Sorted Array

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSecondArrayLow(vector<int>& nums){
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
        return low;
    }

    int secondArraySearch(vector<int>nums,int target){
         int low = findSecondArrayLow(nums);
        int high = nums.size() - 1;
        while(high>=low){
            int mid = (high + low ) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if (nums[mid]>target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return -1;
    }
    int firstArraySearch(vector<int>nums,int target){
         int low = 0;
        int high = findSecondArrayLow(nums) - 1;
        while(high>=low){
            int mid = (high + low ) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if (nums[mid]>target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return -1;
    }
  int search(vector<int>& nums, int target) {
    if(nums.empty()) return -1;
    int pivot = findSecondArrayLow(nums);
    if(target >= nums[pivot] && target <= nums[nums.size()-1]) {
        return secondArraySearch(nums, target);
    } else {
        return firstArraySearch(nums, target);
    }
}
};


int main(){
    vector<int>v = {4,5,6,7,0,1,2};
    int target = 0;
    Solution s;
    cout<<s.search(v,target);
}