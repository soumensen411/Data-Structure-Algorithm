#include <bits/stdc++.h>
using namespace std;

class NumArray
{
    private:
    vector<int> prefix;
public:
    NumArray(vector<int> &nums)
    {
        int n = nums.size();
        prefix.resize(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
            return prefix[right];
        else
        {
            return prefix[right] - prefix[left - 1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main()
{
    vector<int> v = {-2, 0, 3, -5, 2, -1};
    int left = 2, right = 5;
    NumArray N(v);
    cout << N.sumRange(left, right);
}