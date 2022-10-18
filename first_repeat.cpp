#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int *idx = new int[1000000];
    fill_n(idx, 1000000, -1);
    int minIdx = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        if (idx[a[i]] == -1)
            idx[a[i]] = i;
        else
        {
            if (idx[a[i]] < minIdx)
            {
                minIdx = idx[a[i]];
            }
        }
    }
    cout << minIdx;
}