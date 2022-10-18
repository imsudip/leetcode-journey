#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> numsSameConsecDiff(int n, int k)
    {
        vector<int> ans;
        long long left_limit = pow(10, n - 1);
        long long right_limit = pow(10, n) - 1;
        for (int i = 1; i <= 9; i++)
        {
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int num = q.front();
                q.pop();
                if (num >= left_limit && num <= right_limit)
                {
                    ans.push_back(num);
                    continue;
                }
                int lastDigit = num % 10;
                if (lastDigit + k <= 9)
                {
                    q.push(num * 10 + lastDigit + k);
                }
                if (lastDigit - k >= 0 && k != 0)
                {
                    q.push(num * 10 + lastDigit - k);
                }
            }
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
// We can use a queue to solve this problem.
// we will create a for loop from 1 to 9 and push each number in the queue.
// inside the loop we will create two variables left_limit(10^(n-1)) and right_limit(10^n-1).
// then we will create a while loop which will run until the queue is empty.
// we will pop the number from the queue and check if it is in the range of left_limit and right_limit.
// if yes, then we will push it in the answer vector.
// if no, then we will extract the last digit of the number inside a variable lastDigit.
// then we will check if lastDigit + k is less than or equal to 9 or lastDigit - k is greater than or equal to 0 (if k is not equal to 0).
// if yes, then we will push the number * 10 + lastDigit + k and num * 10 + lastDigit - k in the queue respectively.
// and continue the process until the queue is empty.

// Time Complexity: O(2^n)
// Space Complexity: O(2^n)

// pseudo code:
// function numsSameConsecDiff(n, k)
//     ans = []
//     left_limit = 10^(n-1)
//     right_limit = 10^n-1
//     for i = 1 to 9
//        push i in queue
//        while queue is not empty
//            num = pop from queue
//            if num is in the range of left_limit and right_limit
//                push num in ans
//                continue
//            lastDigit = num % 10
//            if lastDigit + k <= 9
//                push num * 10 + lastDigit + k in queue
//            if lastDigit - k >= 0 and k != 0
//                push num * 10 + lastDigit - k in queue
//     return ans
