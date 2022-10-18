/*
Author: Sudip Ghosh (sudipghosh9333@gmail.com)
q967.cpp (c) 2022
Desc: numbers with same consecutive differences
Created:  2022-09-03T16:36:00.228Z
Modified: 2022-09-03T17:34:14.531Z
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void recurse(int n, int k, int num, vector<int> &ans)
    {
        if (n == 0)
        {
            ans.push_back(num);
            return;
        }
        int lastDigit = num % 10;
        if (lastDigit + k <= 9)
        {
            recurse(n - 1, k, num * 10 + lastDigit + k, ans);
        }
        if (lastDigit - k >= 0 && k != 0)
        {
            recurse(n - 1, k, num * 10 + lastDigit - k, ans);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k)
    {
        vector<int> ans;
        for (int i = 1; i <= 9; i++)
        {
            recurse(n - 1, k, i, ans);
        }
        return ans;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    Solution s;
    vector<int> ans = s.numsSameConsecDiff(n, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}

// question: Return all non-negative integers of length n such that the absolute difference between every two consecutive digits is k.
// Note that every number in the answer must not have leading zeros. For example, 01 has one leading zero and is invalid.
// You may return the answer in any order.
// Approach:
// We can use a recursive approach to solve this problem.
// we can make a recursive function which takes the number of digits left(n), the difference between the digits(K), the number formed till now(num) and the answer vector(ans) as the parameters.
// We will start with a digit(1-9) and then check either the digit + k is less than or equal to 9 or digit - k is greater than or equal to 0 (if k is not equal to 0).
// If yes, then we will call the function recursively with n - 1, k, num * 10 + lastDigit + k and if no, then we will return.
// and continue the process until the length of the number is equal to n.
// for example if n = 3 and k=2 and suppose we start with 4 and then check if 4 + 2 is less than or equal to 9 or 4 - 2 is greater than or equal to 0.
// It turns both are true and our next digit can be either 6 or 2.
// so we will call the function recursively with function(n - 1, k, num * 10 + 6) and also with function(n - 1, k, num * 10 + 2).
// We will continue the process until the length of the number is equal to n.
// If the length of the number is equal to n, then we will push the number in the answer vector and return.

// pseuocode:
// recurse_function(n, k, num, ans)
//     if n == 0
//         push num in ans
//         return
//     lastDigit = num % 10
//     if lastDigit + k <= 9
//         function(n - 1, k, num * 10 + lastDigit + k, ans)
//     if lastDigit - k >= 0 and k != 0
//         function(n - 1, k, num * 10 + lastDigit - k, ans)

// function(n, k)
//     loop from 1 to 9
//         call function(n - 1, k, i, ans)
//     print ans

// Language: cpp
// complexity analysis:
// Time complexity: O(2^n)
// Space complexity: O(2^n)
