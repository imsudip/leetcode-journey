/*
Author: Sudip Ghosh (sudipghosh9333@gmail.com)
q1.cpp (c) 2022
Desc: Two sum
Created:  2022-08-29T15:52:21.420Z
Modified: 2022-08-29T15:54:58.056Z
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};