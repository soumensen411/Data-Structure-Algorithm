// 387. First Unique Character in a String

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>v;
        for(int i = 0;i<s.size();i++){
            v[s[i]]++;
        }
        
        for(int i = 0;i<s.size();i++){
            if(v[s[i]] == 1){
                return i;
            } 
        }
        return -1;        
    }
};

int main(){
    string s = "leetcode";
    Solution solve;
    cout<<solve.firstUniqChar(s);
}