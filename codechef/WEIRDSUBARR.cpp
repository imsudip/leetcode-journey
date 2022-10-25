
// rewrite the program using different variable names

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a[200001], b[200001];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        if (n == 1)
        {
            cout << "1" << endl;
            continue;
        }
        for (ll i = 2; i <= n; i++)
        {
            b[i] = a[i] < a[i - 1];
        }
        vector<pair<bool, ll>> store_vec;
        store_vec.push_back({b[2], 1});
        for (ll i = 3; i <= n; i++)
        {
            if (b[i] == store_vec[store_vec.size() - 1].first)
            {
                store_vec[store_vec.size() - 1].second++;
            }
            else
            {
                store_vec.push_back({b[i], 1});
            }
        }
        store_vec.push_back({0, 0});
        ll ans = 0;
        for (ll i = 0; i < store_vec.size() - 1; i++)
        {
            ans += store_vec[i].second * (store_vec[i].second + 1) / 2;
        }
        for (ll i = 0; i < store_vec.size() - 1; i++)
        {
            if (store_vec[i].first == 1)
            {
                ans += store_vec[i].second * store_vec[i + 1].second;
            }
        }
        cout << ans + n << endl;
    }
}