/*
Author: Sudip Ghosh (sudipghosh9333@gmail.com)
q4.cpp (c) 2022
Desc:  Median of Two Sorted Arrays
Created:  2022-09-05T15:41:28.707Z
Modified: 2022-09-05T16:12:57.096Z
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 > n2)
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        int low = 0;
        int high = n1;
        while (low <= high)
        {
            int cut1 = (low + high) / 2;         // partition of nums1
            int cut2 = (n1 + n2 + 1) / 2 - cut1; // partition of nums2
            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];
            if (l1 <= r2 && l2 <= r1)
            {
                if ((n1 + n2) % 2 == 0)
                {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
                else
                {
                    return max(l1, l2);
                }
            }
            else if (l1 > r2)
            {
                high = cut1 - 1;
            }
            else
            {
                low = cut1 + 1;
            }
        }
        return 0.0;
    }
};

// Approach:
// 1. Find the partition point in the smaller array.
// 2. Find the partition point in the larger array.
// 3. Check if the partition points are correct.
// 4. If not, then move the partition points in the smaller array.
// 5. If yes, then find the median.
// 6. Return the median.
//
// Expalnation:
// 1. We will use binary search to find the partition point in the smaller array.
// 2. We will find the partition point in the larger array by using the formula: partition point in the larger array = (n1+n2+1)/2 - partition point in the smaller array.
// 3. We will check if the partition points are correct by checking if the elements to the left of the partition points are smaller than the elements to the right of the partition points.
// 4. If the partition points are not correct, then we will move the partition points in the smaller array.
// 5. If the partition points are correct, then we will find the median.
// 6. If the total number of elements is even, then the median is the average of the maximum of the left partition and the minimum of the right partition.
// 7. If the total number of elements is odd, then the median is the maximum of the left partition.
// 8. Return the median.