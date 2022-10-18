/*
Author: Sudip Ghosh (sudipghosh9333@gmail.com)
q6.cpp (c) 2022
Desc: ZigZag Conversion
Created:  2022-09-08T04:19:56.412Z
Modified: 2022-09-08T10:45:47.886Z
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }
        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;
        for (char c : s)
        {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1)
            {
                goingDown = !goingDown;
            }
            curRow += goingDown ? 1 : -1;
        }
        string ans;
        for (string row : rows)
        {
            ans += row;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.convert("PAYPALISHIRING", 3) << endl;
    return 0;
}

// question: https://leetcode.com/problems/zigzag-conversion/
// Approach:
// After looking at the question, I thought of using a 2D array to store the characters in the zigzag pattern. But, I realized that it would be a waste of space. So, I thought of using a vector of strings to store the characters in the zigzag pattern. I used a boolean variable goingDown to keep track of the direction of the zigzag pattern. If goingDown is true, then I increment the row number. If goingDown is false, then I decrement the row number. I used a for loop to iterate through the string s. I used a if-else statement to check if the row number is 0 or numRows - 1. If it is, then I change the value of goingDown. I used a for loop to iterate through the vector of strings and append the characters to the string ans. I returned the string ans.

// Complexity analysis:
// Time complexity:
// we only iterate through the string s once. So, the time complexity is O(n).
// Space complexity:
// we use a vector of strings to store the characters in the zigzag pattern. So, the space complexity is O(n).

// Pseudo code:
// function convert(s, numRows)
//     if numRows is equal to 1
//         return s  // as there will be no zigzag pattern
//     create a vector of strings rows with size min(numRows, size of s)
//     create an integer curRow and initialize it to 0
//     create a boolean variable goingDown and initialize it to false
//     for each character c in s
//         append c to rows[curRow]
//         if curRow is equal to 0 or curRow is equal to numRows - 1
//             change the value of goingDown
//         if goingDown is true
//             increment curRow
//         else
//             decrement curRow
//     create a string ans
//     for each string row in rows
//         append row to ans
//     return ans
// end function
