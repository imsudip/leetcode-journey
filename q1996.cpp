/*
Author: Sudip Ghosh (sudipghosh9333@gmail.com)
q1996.cpp (c) 2022
Desc: The Number of Weak Characters in the Game
Created:  Fri Sep 09 2022 11:04:35 GMT+0530 (India Standard Time)
Modified: 2022-09-15T03:38:45.151Z
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if (a[0] != b[0])
        {
            return a[0] > b[0];
        }
        return a[1] < b[1];
    }
    int numberOfWeakCharacters(vector<vector<int>> &properties)
    {
        sort(properties.begin(), properties.end(), comp);
        int ans = 0;
        int maxDef = 0;
        for (auto x : properties)
        {
            if (x[1] < maxDef)
            {
                ans++;
            }
            maxDef = max(maxDef, x[1]);
        }
        return ans;
    }
};