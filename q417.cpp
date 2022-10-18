#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {

        int rlen = heights.size();
        int clen = heights[0].size();

        vector<vector<int>> output;
        vector<vector<bool>> atlantic(rlen, vector<bool>(clen, false));
        vector<vector<bool>> pacific(rlen, vector<bool>(clen, false));

        // Do a DFS on all nodes at the pacific end and the atlantic end:
        for (int r = 0; r < rlen; r++)
        {
            for (int c = 0; c < clen; c++)
            {
                if (r == 0 || c == 0)
                {
                    dfs(pacific, heights, r, c, 0);
                }
                if (r == rlen - 1 || c == clen - 1)
                {
                    dfs(atlantic, heights, r, c, 0);
                }
            }
        }

        // Check which locations can reach both pacific and atlantic:
        for (int r = 0; r < rlen; r++)
        {
            for (int c = 0; c < clen; c++)
            {
                if (atlantic[r][c] && pacific[r][c])
                {
                    output.push_back({r, c});
                }
            }
        }
        return output;
    }

    // Go to a node - all the larger ones around it can reach the current sea:
    void dfs(vector<vector<bool>> &sea, vector<vector<int>> &grid, int r, int c, int prev)
    {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size())
            return;
        if (grid[r][c] < prev)
            return;
        if (sea[r][c])
            return;

        sea[r][c] = true;
        dfs(sea, grid, r + 1, c, grid[r][c]); // bottom
        dfs(sea, grid, r - 1, c, grid[r][c]); // top
        dfs(sea, grid, r, c - 1, grid[r][c]); // left
        dfs(sea, grid, r, c + 1, grid[r][c]); // right
    }
};

int main()
{
    Solution s;
    vector<vector<int>> heights = {{1, 2, 2, 3, 5},
                                   {3, 2, 3, 4, 4},
                                   {2, 4, 5, 3, 1},
                                   {6, 7, 1, 4, 5},
                                   {5, 1, 1, 2, 4}};
    vector<vector<int>> output = s.pacificAtlantic(heights);
    for (auto v : output)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}