#include <bits/stdc++.h>
using namespace std;

int n, a[102], b[102], ans, query[102][20001];
void dfs(int idx, int x, int y)
{
    if (idx == n + 1)
    {
        ans = max(ans, (min(x, y)));
        return;
    }
    if (query[idx][x] >= y && query[idx][x] != 0)
    {
        return;
    }
    query[idx][x] = y;
    dfs(idx + 1, x + a[idx], y);
    dfs(idx + 1, x, y + b[idx]);
}
void solveProblem()
{

    cin >> n;
    // fill q with 0
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < 20001; j++)
        {
            query[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    ans = 0;
    dfs(1, 0, 0);
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solveProblem();
    }
    return 0;
}