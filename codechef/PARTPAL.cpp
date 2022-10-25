#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string str;
        cin >> str;
        if (str[0] == '0')
        {
            for (int i = 0; i < 2 * n; i++)
            {
                if (str[i] == '1')
                {
                    str[i] = '0';
                }
                else
                {
                    str[i] = '1';
                }
            }
        }
        vector<ll> vec;
        ll count;
        ll flag = 0;
        ll p;
        for (int i = 0; i < 2 * n; i++)
        {
            if (str[i] == '0')
            {
                vec.push_back(i);
            }
            if (str[i] != str[2 * n - i - 1])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            cout << "1\n";
            cout << 2 * n << "\n";
            continue;
        }
        if (vec.size() == 0)
        {
            cout << "-1\n";
        }
        else
        {
            count = 2 * n - 1 - vec.back();
            for (int i = vec.size() - 1; i >= 1; i--)
            {
                if (vec[i] - vec[i - 1] - 1 != count)
                {
                    flag = 1;
                    cout << "2\n";
                    cout << vec[i - 1] + 1 << " " << 2 * n - 1 - vec[i - 1] << "\n";
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "2\n";
                cout << vec[vec.size() - 2] + 2 << " " << 2 * n - 2 - vec[vec.size() - 2] << "\n";
            }
        }
    }
    return 0;
}
