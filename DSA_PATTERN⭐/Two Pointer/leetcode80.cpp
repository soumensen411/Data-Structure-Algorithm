// 80 Remove Duplicates from Sorted Array II

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
        {
            return n;
        }
        int i = 2;
        int j = 2;
        while (j < nums.size())
        {
            if (nums[j] != nums[i - 2])
            {
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
};

int main()
{
    vector<int> v = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    Solution s;
    cout << s.removeDuplicates(v);
}