/*
Author: Sudip Ghosh (sudipghosh9333@gmail.com)
q1328.cpp (c) 2022
Desc: Break a Palindrome
Created:  Mon Oct 10 2022 14:43:19 GMT+0530 (India Standard Time)
Modified: !date!
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n == 1) return "";
        for(int i = 0; i < n/2; i++){
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[n-1] = 'b';
        return palindrome;
        
    }
};

int main(){
    Solution s;
    cout << s.breakPalindrome("abccba") << endl;
    return 0;
}

// Language: cpp
// question: https://leetcode.com/problems/break-a-palindrome/

// Approach:
// We can make the following inference from the problem statement:
// 1. If the length of the string is 1, then we cannot break the palindrome.
// 2. We can process only the first half of the string to break the palindrome.
// 3. The most lexographically smaller string is "a" and the most lexographically larger string is "z".
// 4. So, we can replace the first non-'a' character with 'a' to get the smallest string(lexographically) that is not a palindrome.
// 5. If all the characters are 'a', then we can replace the last character with 'b' to get the smallest string(lexographically) that is not a palindrome.

// Psuedocode:
// function breakPalindrome(palindrome):
//     n = length of palindrome
//     if n == 1:
//         return ""
//     for i = 0 to n/2:
//         if palindrome[i] != 'a':
//             palindrome[i] = 'a'
//             return palindrome
//     palindrome[n-1] = 'b'
//     return palindrome

// Time Complexity: O(n)
// Space Complexity: O(1)

