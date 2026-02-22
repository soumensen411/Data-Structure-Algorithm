// 1189. Maximum Number of Balloons
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {

        unordered_map<char,int>have;
        unordered_map<char,int>need;
        int res = INT_MAX;
        for(int i = 0;i<text.size();i++){
            have[text[i]]++;
        }
        need['b'] = 1;
        need['a'] = 1;
        need['l'] = 2;
        need['o'] = 2;
        need['n'] = 1;
        for(auto i : need){
            int c = i.first;
            int fneed = i.second;
            int fhave = have[c];

            int times = fhave/fneed;
            res = min(res,times);
        }
        return res;
    }
};


int main(){
    string s =  "loonbalxballpoon";
    Solution solve;
    cout<<solve.maxNumberOfBalloons(s);
}
