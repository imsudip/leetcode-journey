// Problem
// Chef is given two strings AA and BB of length NN containing lowercase English letters.

// Chef can rearrange both the strings in any way he wants. He wants to minimize the length of LCS (Longest Common Subsequence) of both the strings.

// Find the minimum length of LCS of AA and BB if he optimally rearranges both the strings.

// Input
// The first line of the input contains a single integer TT denoting the number of test cases. The description of TT test cases follows.
// The first line of each test case contains a single integer NN.
// The second line contains a single string AA of length NN.
// The third line contains a single string BB of length NN.
// Output
// For each test case, print a single line containing one integer ― the minimum length of LCS of AA and BB if Chef optimally rearranges both the strings.

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
        string s1, s2;
        cin >> s1 >> s2;
        map<char, int> m;
        for (int i = 0; i < n; i++)
        {
            m[s1[i]]++;
        }
        map<char, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[s2[i]]++;
        }
        int ans = 0;
        for (char a = 'a'; a <= 'z'; a++)
        {
            ans = max(ans, min(m[a], mp[a]));
        }
        cout << ans << endl;
    }
    return 0;
}