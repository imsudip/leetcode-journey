/*
Author: Sudip Ghosh (sudipghosh9333@gmail.com)
q363.cpp (c) 2022
Desc: Max sum of rectangle no larger than K
Created:  2022-08-27T07:27:59.008Z
Modified: 2022-08-27T08:11:41.430Z
*/

#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int m = matrix.size();    // rows of matrix
        int n = matrix[0].size(); // columns of matrix
        int maxSum = INT_MIN;
        // for each row
        for (int left = 0; left < n; left++)
        {
            vector<int> rowSum(m, 0); // rowSum[i] = sum of row i
            // for each column
            for (int right = left; right < n; right++)
            {
                // for each row
                for (int i = 0; i < m; i++)
                {
                    rowSum[i] += matrix[i][right];
                }
                set<int> prefixSum;
                prefixSum.insert(0);
                int currSum = 0;
                for (int i = 0; i < m; i++)
                {
                    currSum += rowSum[i];
                    auto it = prefixSum.lower_bound(currSum - k);
                    if (it != prefixSum.end())
                    {
                        maxSum = max(maxSum, currSum - *it);
                    }
                    prefixSum.insert(currSum);
                }
            }
        }
        return maxSum;
    }

    // explanation of above solution:
    // first, we find the sum of each row.
    // then, we find the sum of each submatrix.
    // we do this by keeping track of the prefix sum of each row.
    // we use a set to keep track of the prefix sum.
    // we use a lower_bound function to find the prefix sum that is closest to the current sum - k.
    // if the prefix sum is found, we update the maxSum.
    // we do this for each row.
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1, 0, 1}, {0, -2, 3}};
    cout << s.maxSumSubmatrix(matrix, 2) << endl;
    return 0;
}
