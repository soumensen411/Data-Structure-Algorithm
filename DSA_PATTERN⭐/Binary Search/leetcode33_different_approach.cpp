// 33. Search in Rotated Sorted Array
/*
50 60 70 80 90 10 20 30 40
if we find 90 and our mid = 70 then only one case -we need to go right
but if we find 30 but our mid is 70 two case appear
Part-1=>
{
case-1: we can go left because 30 is less then our mid.
case-2: As the array is rotated sort so we find the smallest value in the left part also.
}
50 60 70 80 90 10 20 30 40
Part-2=>
if we want to find 10 and our mid is 30 then we simply go left but if  we want to larger Value 70 and Mid is 20 then  we can go left also in right side there is a larger value.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (high >= low)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] > nums[n - 1])
            {
                if (nums[mid] < target)
                {
                    low = mid + 1;
                }
                else
                {
                    if (nums[0] > target)
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
            }
            else
            {
                if (nums[mid] > target)
                    high = mid - 1;
                else
                {
                    if (nums[n - 1] < target)
                        high = mid - 1;
                    else
                        low = mid + 1;
                }
            }
        }
        return -1;
    }
};

int main(){
    vector<int>v = {4,5,6,7,0,1,2};
    int target = 0;
    Solution s;
    cout<<s.search(v,target);
}