// 125. Valid Palindrome

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int left = 0;
        int right = s.size() - 1;
        while(right > left){
            while(left<right && !isalnum(s[left]))
                left++;
            
            while(left<right && !isalnum(s[right]))
                right--;
            
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main(){
    string s = "A man, a plan, a canal: Panama";
    Solution sol;
    cout<<(sol.isPalindrome(s)?"true":"false");
}