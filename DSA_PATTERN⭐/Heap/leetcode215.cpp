// 215. Kth Largest Element in an Array

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = nums.size();
        for (int i = 0; i < k; i++)
        {
            pq.push(nums[i]);
        }
        for (int i = k; i < n; i++)
        {
            if (nums[i] <= pq.top())
            {
                continue;
            }
            else
            {
                pq.push(nums[i]);
                pq.pop();
            }
        }
        return pq.top();
    }
};

int main()
{
    vector<int> v = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;
    Solution s;
    cout << s.findKthLargest(v, k);
}