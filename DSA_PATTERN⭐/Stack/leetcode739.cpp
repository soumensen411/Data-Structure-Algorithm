// 739. Daily Temperatures

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        stack<int> st;
        vector<int> res(n);
        res[n - 1] = 0;
        st.push(n - 1);
        for (int i = n - 2; i >= 0; i--)
        {
            while (!st.empty() && temperatures[i] >= temperatures[st.top()])
            {
                st.pop();
            }
            if (st.empty())
            {
                res[i] = 0;
            }
            else
            {
                res[i] = st.top() - i;
            }
            st.push(i);
        }
        return res;
    }
};

int main()
{
    vector<int> v = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution s;
    vector<int> res = s.dailyTemperatures(v);
    for (auto i : res)
    {
        cout << i << " ";
    }
}

// Output: [1,1,4,2,1,1,0,0]}