// Fruit Into Baskets
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int low = 0, high = 0, res = INT_MIN;
        unordered_map<int, int> frequency;
        for (high = 0; high < fruits.size(); high++)
        {
            frequency[fruits[high]]++;
            while (frequency.size() > 2)
            {
                frequency[fruits[low]]--;
                if (frequency[fruits[low]] == 0)
                    frequency.erase(fruits[low]);
                low++;
            }
            int dist = high - low + 1;
            res = max(res, dist);
        }
        return res;
    }
};
int main(){
    vector<int>fruits = {1,2,3,2,2};
    Solution s;
    cout<<s.totalFruit(fruits);
}
