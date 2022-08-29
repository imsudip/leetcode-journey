/*
Author: Sudip Ghosh (sudipghosh9333@gmail.com)
q869.cpp (c) 2022
Desc: Reordered Power of 2
Created:  2022-08-26T06:39:09.747Z
Modified: 2022-08-26T10:33:04.179Z
*/
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        string s = to_string(n);
        sort(s.begin(), s.end());
        vector<string> powers;
        for (int i = 0; i < 30; i++)
        {
            int num = pow(2, i);
            string numString = to_string(num);
            sort(numString.begin(), numString.end());
            powers.push_back(numString);
        }
        for (int i = 0; i < powers.size(); i++)
        {
            if (s == powers[i])
                return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    cout << s.reorderedPowerOf2(2140) << endl;
    return 0;
}