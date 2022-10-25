#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                st.push(a[i]);
            }
            else
            {
                if (a[i] != st.top())
                {
                    st.pop();
                    ans++;
                }
                else
                {
                    st.push(a[i]);
                }
            }
        }
        while (st.size() >= 2)
        {
            int temp = st.top();
            st.pop();
            if (temp == st.top())
            {
                st.pop();
                st.push(0);
            }
            else
            {
                ans++;
                st.pop();
            }
        }
        cout << ans << endl;
    }

    return 0;
}