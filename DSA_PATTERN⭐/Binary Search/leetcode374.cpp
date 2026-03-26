// 374. Guess Number Higher or Lower


#include<bits/stdc++.h>
using namespace std;
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 */
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long low = 1;
        long long high = n;
        while (n >= low) {
            long long mid = (low + high) / 2;
            long long res = guess(mid);
            if (res == 0) {
                return mid;
            } else if (res < 0) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};

int main(){
    int n;
    Solution s;
    cout<<s.guessNumber(n);
}