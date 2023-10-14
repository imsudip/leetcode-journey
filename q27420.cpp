class Solution {
public:

    int solve(int ind, int task, vector<int> &c, vector<int> &t, vector<vector<int>> &dp){
        if(task <= 0) return 0;
        if(ind == -1) return 1e9;
        if(dp[ind][task] != -1) return dp[ind][task];
        return dp[ind][task] = min(c[ind] + solve(ind - 1, task - t[ind] - 1, c, t, dp), solve(ind - 1, task, c, t, dp));
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(n - 1, n, cost, time, dp);
    }
};



// Approach
// Think like that I will tell my function that I will provide you ind and number of walls to be painted from index 0 to that ind with minimum cost.
// So initially I will call with index as n - 1 and number of walls as n.
// So my function call looks like :- solve(n - 1, n, cost, time).
// Now I have 2 choices either to paint current wall or not.

// If i paint current wall then I will paint the current wall and I can use my free worker for the time time[ind], so again we will ask function to give the minimum cost to paint the walls from 0 to ind - 1 and now the number of walls to be painted are wallsToPaint - time[ind] - 1. So function call looks like cost[ind] + solve(ind - 1, tasks - time[ind] - 1, cost, time).
// If I do not paint the current wall the simply I will ask my function to find the minimum cost from the array 0 to ind - 1 and number of walls tot be painted remains same only. So my function call will look like solve(ind - 1, tasks, cost, time).
// Base cases can be like if there are no tasks to do means no walls to be painted then cost would be 0 and if I ended with array with some walls to be painted then we will return some huge value as this is not possible.


// Time Complexity:O(n^2)
// Space Complexity:O(n^2)
