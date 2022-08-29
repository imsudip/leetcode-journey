#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int a;
    vector<string> msg{"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    cin >> a;
    for (const string &word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}