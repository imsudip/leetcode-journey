/*
Author: Sudip Ghosh (sudipghosh9333@gmail.com)
383.cpp (c) 2022
Desc: Q383. Ransom Note
Created:  2022-08-26T06:04:07.309Z
Modified: 2022-08-26T06:33:49.356Z
*/
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        for (int i = 0; i < ransomNote.length(); i++)
        {
            int index = magazine.find(ransomNote[i]);
            if (index == -1)
            {
                return false;
            }
            magazine.erase(index, 1);
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.canConstruct("a", "b") << endl;
    cout << s.canConstruct("aa", "ab") << endl;
    cout << s.canConstruct("aa", "aab") << endl;
    return 0;
}