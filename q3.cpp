/*
Author: Sudip Ghosh (sudipghosh9333@gmail.com)
q3.cpp (c) 2022
Desc: Longest substring without repeating characters
Created:  2022-08-29T16:16:33.650Z
Modified: 2022-08-29T16:36:48.183Z
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> v(256, 0);
        int start = 0, lString = 0;
        for (int end = 0; end < s.length(); end++)
        {
            v[s[end]]++;
            while (v[s[end]] > 1)
            {

                v[s[start]]--;
                start++;
            }
            lString = max(lString, end - start + 1);
        }
        return lString;
    }
    // explanation for the above solution:
    // we start from the beginning of the string and keep track of the start and end of the substring.
    // we keep track of the count of each character in the substring.
    // if the count of the character is greater than 1, we move the start of the substring to the next character.
    // we keep track of the maximum length of the substring.
    // we return the maximum length of the substring.
};

int main()
{
    Solution s;
    string str = "abcabcbb";
    cout << s.lengthOfLongestSubstring(str);
    return 0;
}
