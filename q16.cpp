/*
Author: Sudip Ghosh (sudipghosh9333@gmail.com)
q16.cpp (c) 2022
Desc: 3Sum Closest
Created:  Sat Oct 08 2022 16:13:14 GMT+0530 (India Standard Time)
Modified: 2022-10-08T10:53:59.682Z
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        int ans = 0;
        int minDiff = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(sum - target);
                if (diff < minDiff)
                {
                    minDiff = diff;
                    ans = sum;
                }
                if (sum < target)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    // [1,1,1,1]
    // -100
    vector<int> nums = {1, 1, 1, 1};
    cout << s.threeSumClosest(nums, -100) << endl;
    return 0;
}

// question: https://leetcode.com/problems/3sum-closest/
// Approach:
// After looking at the question, I thought of using a 2 pointer approach. I used a for loop to iterate through the vector nums. I used a while loop to iterate through the vector nums. I used a if-else statement to check if the sum is less than the target. If it is, then I increment the value of j. If it is not, then I decrement the value of k. I used a if statement to check if the difference between the sum and the target is less than the minDiff. If it is, then I update the value of minDiff and ans.
// Complexity analysis:
// Time complexity: O(n^2)
// Space complexity: O(1)
