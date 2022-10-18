/*
Author: Sudip Ghosh (sudipghosh9333@gmail.com)
q1.cpp (c) 2022
Desc: Two sum
Created:  2022-08-29T15:52:21.420Z
Modified: 2022-09-03T16:23:52.028Z
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
// question: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.
// Approach:
// 1. Take two for loops
// 2. In the first for loop, take the first element and in the second for loop, take the second element
// 3. Check if the sum of the two elements is equal to the target
// 4. If yes, then push the indices of the two elements in the vector and return the vector
// 5. If no, then continue the loop
// 6. If no such pair is found, then return an empty vector
