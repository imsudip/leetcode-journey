/*
Author: Sudip Ghosh (sudipghosh9333@gmail.com)
q48.cpp (c) 2022
Desc: rotate matrix 90 degree
Created:  2022-08-30T08:12:29.967Z
Modified: 2022-08-30T08:16:48.855Z
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // transpose
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = i; j < matrix.size(); j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // reverse each row
        for (int i = 0; i < matrix.size(); i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
