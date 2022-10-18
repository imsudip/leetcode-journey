/*
Author: Siddhant Majumder (siddhantmajumder@gmail.com)
q9.cpp (c) 2022
Desc: Palindrome Number 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        long int digit,reverse=0,original=x;
        if(x<0){
            return false;
        }
        while(x!=0){
            digit = x % 10;
            reverse = reverse*10 + digit;
            x /= 10;
        }
        if(reverse==original){
            return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    cout <<"-121: " << s.isPalindrome(-121) << endl;
    cout <<"121: " << s.isPalindrome(121) << endl;
    return 0;
}

// question: https://leetcode.com/problems/palindrome-number
// Approach:
// If the number is less than 0 false is returned(considering the sample outputs)
// Each digit is extracted by using modulus 10 on the number.
// The reversed number is formed by placing each successive digit in one's place of the reverse number.
// Divide original number by 10 until it becomes equal to 0.
// If the number formed is equal to original number we return true else we return false.
// Time complexity: O(logN)[N -> original number]
// Space complexity: O(1)