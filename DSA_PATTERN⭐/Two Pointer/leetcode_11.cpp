/*
   _____                                 
  / ___/____  __  ______ ___  ___  ____  
  \__ \/ __ \/ / / / __ `__ \/ _ \/ __ \ 
 ___/ / /_/ / /_/ / / / / / /  __/ / / / 
/____/\____/\__,_/_/ /_/ /_/\___/_/ /_/  
         
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& v) {
        int left = 0, right = v.size() - 1;
        int maxWater = 0;
        while(right > left){
            int currWater = min(v[left],v[right])*(right - left);
            maxWater = max(maxWater,currWater);
            if(v[right]>=v[left]){
                left++;
            }
            else{
                right--;
            }
        }return maxWater;
    }
};

int main() {
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution solution;
    cout << solution.maxArea(heights) << '\n';
    return 0;
}