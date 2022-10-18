/*
Author: Sudip Ghosh (sudipghosh9333@gmail.com)
q5.cpp (c) 2022
Desc: Longest palindromic substring
Created:  2022-08-29T16:36:55.613Z
Modified: 2022-09-08T19:39:45.742Z
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int expandAroundCenter(string s, int left, int right)
    {
        int L = left, R = right;
        while (L >= 0 && R < s.length() && s[L] == s[R])
        {
            L--;
            R++;
        }
        return R - L - 1;
    }
    string longestPalindrome(string s)
    {
        int n = s.length();
        int start = 0, end = 0;
        for (int i = 0; i < n; i++)
        {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);
            if (len > end - start)
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
