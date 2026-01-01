// https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1
#include <bits/stdc++.h>
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl '\n'
#define ll long long
#define yes "YES\n"
#define no "NO\n"
using namespace std;
void inputOutput(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int left = 0;
        int right = arr.size() - 1;
        while(right > left){
            if(arr[left] == 1 && arr[right] == 0){
                swap(arr[left],arr[right]);
                left++;
                right--;
            }
            else if(arr[left] == 0)
            left++;
            else right--;
        }
    }
};
void solve(){
Solution s;
vector<int>v = {0, 0, 1, 1, 0};
s.segregate0and1(v);
for(int x : v) cout << x << " ";
cout << endl;
}
int main()
{
    solve();
    return 0;
}
