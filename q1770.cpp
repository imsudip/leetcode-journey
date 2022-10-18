/*
Author: Sudip Ghosh (sudipghosh9333@gmail.com)
q1770.cpp (c) 2022
Desc: Maximum Score from Performing Multiplication Operations
Created:  Fri Sep 16 2022 10:39:29 GMT+0530 (India Standard Time)
Modified: 2022-09-18T03:34:25.605Z
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        sort(nums.begin(), nums.end());
        sort(multipliers.begin(), multipliers.end(), greater<int>());
        int n = nums.size();
        int m = multipliers.size();
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            if (multipliers[i] * nums[0] > multipliers[i] * nums[n - 1])
            {
                ans += multipliers[i] * nums[0];
                nums.erase(nums.begin());
                n--;
            }
            else
            {
                ans += multipliers[i] * nums[n - 1];
                nums.erase(nums.end() - 1);
                n--;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    // [-5,-3,-3,-2,7,1]
    // [-10,-5,3,4,6]
    vector<int> v1 = {-5, -3, -3, -2, 7, 1};
    vector<int> v2 = {-10, -5, 3, 4, 6};
    cout << s.maximumScore(v1, v2);
    return 0;
}

// wrong answer