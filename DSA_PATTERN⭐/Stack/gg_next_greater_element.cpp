// Next Greater Element

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextLargerElement(vector<int>& arr)
    {
        
        int n = arr.size();
        vector<int> res(n);
        stack<int> st;
        res[n - 1] = -1;
        st.push(arr[n - 1]);
        for (int i = n - 2; i >= 0; i--){
            while(!st.empty() && st.top()<= arr[i]){
                st.pop();
            }
            if(st.empty()){
                
                res[i] = -1;
            }
            else{
                res[i] = st.top();
            }
            st.push(arr[i]);
        }
        return res;
    }
};

int main(){
    vector<int> v = {6, 8, 0, 1, 3};
    Solution s;
    vector<int>res = s.nextLargerElement(v);
    for(auto i:res){
        cout<<i<<" ";
    }
}