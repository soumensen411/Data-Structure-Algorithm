// 219. Contains Duplicate II

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i = 0;i<n;i++){
            if(mp.count(nums[i])){
                int diff = abs(i - mp[nums[i]]);
                if(diff <= k){
                    return true;
                }
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};

int main(){
    vector<int>v = {1,2,3,1,2,3};
    int k = 2;
    Solution s;
    cout<<(s.containsNearbyDuplicate(v,k)?"True":"False");
}