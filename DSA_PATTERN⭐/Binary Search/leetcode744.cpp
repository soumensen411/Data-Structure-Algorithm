// 744. Find Smallest Letter Greater Than Target
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int low = 0;
        int high = letters.size() - 1;
        char ans = letters[0];
        while (high >= low)
        {
            int mid = (high + low) / 2;
            if (letters[mid] > target)
            {
                ans = letters[mid];
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if (ans < target)
            return letters[0];
        else
            return ans;
    }
};

int main()
{
    vector<char> v = {'c', 'f', 'j'};
    char target = 'a';
    Solution s;
    cout << s.nextGreatestLetter(v, target);
}