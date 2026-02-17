// previous Greater Element II

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextPreviousElements(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> res(n);
        stack<int> st;
        res[0] = -1;
        st.push(arr[0]);
        for (int i = 1; i < arr.size(); i++)
        {
            while (!st.empty() && st.top() <= arr[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                res[i] = -1;
                st.push(arr[i]);
            }
            else
            {
                res[i] = st.top();
                st.push(arr[i]);
            }
        }
        return res;
    }
};

int main()
{
    vector<int> v = {4, 2, 1, 5, 3};
    Solution s;
    vector<int> solve = s.nextPreviousElements(v);
    for (auto i : solve)
    {
        cout << i << " ";
    }
}