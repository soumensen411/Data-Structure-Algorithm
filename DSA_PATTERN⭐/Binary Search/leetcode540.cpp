#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans;
        map<int,int>mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto i:mp){
            if(i.second == 1){
                ans = i.first;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> v = {1,1,2,3,3,4,4,8,8};
    Solution s;
    cout<<s.singleNonDuplicate(v);
}