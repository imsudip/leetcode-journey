/*
Author: Sudip Ghosh (sudipghosh9333@gmail.com)
q2007.cpp (c) 2022
Desc: Find original array from doubled array
Created:  Thu Sep 15 2022 09:08:58 GMT+0530 (India Standard Time)
Modified: 2022-09-15T04:23:38.319Z
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        if (changed.size() % 2 != 0)
            return {};
        multiset<int> s;
        for (int i : changed)
            s.insert(i);
        vector<int> ans;
        while (!s.empty())
        {
            int x = *s.begin();
            s.erase(s.begin());
            if (s.find(x * 2) == s.end()) // if 2*x not found
                return {};
            s.erase(s.find(x * 2));
            ans.push_back(x);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 3, 4, 2, 6, 8};
    vector<int> ans = s.findOriginalArray(v);
    for (int i : ans)
        cout << i << " ";
    return 0;
}

// Question: Find original array from doubled array

// Approach:
// If the size of the array is odd, then return empty array (as the array cannot be divided into pairs)
// We can use multiset to store the elements of the array.(multiset is a set which can have multiple elements with same value and it is sorted in ascending order)
// We can iterate over the multiset and for each element we can check if the element*2 is present in the multiset or not.
// If it is present then we can erase the element*2 from the multiset and push the element in the answer vector.
// If it is not present then we can return an empty vector. (as the array cannot be divided into pairs)
// If we are able to iterate over the multiset and erase all the elements then we can return the answer vector else we can return an empty vector.

// Time Complexity: O(nlogn) (as we are using multiset)
// Space Complexity: O(n) (as we are using multiset)

// psedo code:
// function findOriginalArray(vector<int> changed)
//     if size of changed is odd
//         return empty vector
//     create a multiset s
//     for each element i in changed
//         insert i in s
//     create a vector ans
//     while s is not empty
//         create a variable x and assign it to the first element of s
//         erase the first element of s
//         if s.find(x*2) is not equal to s.end() (i.e. x*2 is present in s)
//             erase s.find(x*2)
//             push x in ans
//         else
//             return empty vector
//     return ans
// end function
