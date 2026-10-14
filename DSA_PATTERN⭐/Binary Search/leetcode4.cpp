// Median of two sorted array

/*
   _____
  / ___/____  __  ______ ___  ___  ____
  \__ \/ __ \/ / / / __ `__ \/ _ \/ __ \
 ___/ / /_/ / /_/ / / / / / /  __/ / / /
/____/\____/\__,_/_/ /_/ /_/\___/_/ /_/

*/

#include <bits/stdc++.h>
using namespace std;

class SolutionMerge
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0;
        vector<int> final;
        while (i < n && j < m)
        {
            if ((j < m && i < n) && (nums1[i] < nums2[j]))
            {
                final.push_back(nums1[i]);
                i++;
            }
            else
            {
                final.push_back(nums2[j]);
                j++;
            }
        }
        while (i < n)
        {
            final.push_back(nums1[i]);
            i++;
        }
        while (j < m)
        {
            final.push_back(nums2[j]);
            j++;
        }
        double ans;
        if (final.size() % 2 == 0)
        {
            int low = 0, high = final.size() - 1;
            int mid = (low + high) / 2;
            ans = (final[mid + 1] + final[mid]) / 2.0;
        }
        else
        {
            int low = 0, high = final.size() - 1;
            int mid = (low + high) / 2.0;
            ans = final[mid];
        }
        return ans;
    }
};

class SolutionBinarySearch
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        int left = (n1 + n2 + 1) / 2;
        int low = 0;
        int high = n1;
        while (high >= low)
        {
            int mid1 = low + (high - low) / 2;
            int mid2 = left - mid1;
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;
            if (mid1 < n1)
                r1 = nums1[mid1];
            if (mid2 < n2)
                r2 = nums2[mid2];
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];
            if (l1 <= r2 && l2 <= r1)
            {
                if ((n1 + n2) % 2 != 0)
                    return max(l1, l2);
                else
                {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
            }
            if (l1 > r2)
                high = mid1 - 1;
            else
                low = mid1 + 1;
        }
        return 0;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> nums1(n), nums2(m);
    for (int &value : nums1)
        cin >> value;
    for (int &value : nums2)
        cin >> value;

    SolutionMerge mergeSolution;
    SolutionBinarySearch binarySearchSolution;
    cout << mergeSolution.findMedianSortedArrays(nums1, nums2) << '\n';
    cout << binarySearchSolution.findMedianSortedArrays(nums1, nums2) << '\n';
}