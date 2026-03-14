// 278. First Bad Version

#include<bits/stdc++.h>
using namespace std;

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long low = 0;
        long long high = n;
        long long ans;
        while(high>=low){
            long long mid = (low + high) / 2;
            if(isBadVersion(mid) == true){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};

int main(){
    int n = 5; 
    Solution s;
    cout<<s.firstBadVersion(n); // it's not working because isBadVersion function is not defined.
}