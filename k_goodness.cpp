#include <iostream>
#include <string>
using namespace std;

int main()
{
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int goodness = 0;
        for (int j = 0; j < n / 2; j++)
        {
            if (s[j] != s[n - j - 1])
            {
                goodness++;
            }
        }
        int operations = 0;
        if (goodness == k)
        {
            operations = 0;
        }
        else if (goodness > k)
        {
            operations = goodness - k;
        }
        else
        {
            operations = k - goodness;
        }
        cout << "Case #" << i + 1 << ": " << operations << endl;
    }
}