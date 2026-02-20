// 503. Next Greater Element II

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return {};

        vector<int> res(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            st.push(nums[i]);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i])
            {
                st.pop();
            }
            if (!st.empty())
                res[i] = st.top();

            st.push(nums[i]);
        }

        return res;
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 3};
    Solution s;
    vector<int> res = s.nextGreaterElements(v);
    for (int i : res)
    {
        cout << i << " ";
    }
}