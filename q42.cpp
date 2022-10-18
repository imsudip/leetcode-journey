/*
Author: Sudip Ghosh (sudipghosh9333@gmail.com)
q42.cpp (c) 2022
Desc: Trapping Rain water
Created:  Sun Sep 18 2022 09:04:48 GMT+0530 (India Standard Time)
Modified: 2022-09-18T03:36:21.124Z
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        vector<int> leftDP;
        vector<int> rightDP;
        int n = height.size();
        int ans = 0;
        leftDP.push_back(height[0]);
        rightDP.push_back(height[n - 1]);
        for (int i = 1; i < n; i++)
        {
            leftDP.push_back(max(leftDP[i - 1], height[i]));
        }
        for (int i = n - 2; i >= 0; i--)
        {
            rightDP.push_back(max(rightDP[n - i - 2], height[i]));
        }
        reverse(rightDP.begin(), rightDP.end());
        for (int i = 0; i < n; i++)
        {
            ans += min(leftDP[i], rightDP[i]) - height[i];
        }
        return ans;
    }
};