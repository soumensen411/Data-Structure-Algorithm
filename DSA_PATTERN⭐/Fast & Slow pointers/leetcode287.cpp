// 287. Find the Duplicate Number

#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while(true){
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
            if(slow == fast){
                slow = 0;
                while(slow != fast){
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return slow;
            }
        }
        return slow;
    }
};

int main(){
    vector<int>v = {1,3,4,2,2};
    Solution s;
    cout<<s.findDuplicate(v);
}
