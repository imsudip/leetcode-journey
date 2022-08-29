/*
Author: Sudip Ghosh (sudipghosh9333@gmail.com)
chef_laddo.cpp (c) 2022
Desc: chefs and kids
Created:  2022-08-28T09:10:47.694Z
Modified: 2022-08-28T09:20:28.638Z
*/

#include <iostream>

using namespace std;

int countLaddo(int n, int arr[])
{
    int count = 1;
    int currLaddo = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            currLaddo++;
        }
        else
        {
            currLaddo = 1;
        }
        count += currLaddo;
    }
    return count;
}

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << countLaddo(n, arr) << endl;
}