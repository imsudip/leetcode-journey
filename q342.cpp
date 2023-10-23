/*Author: Sk Firoj(sk.firoj9732@gmail.com)
  q342.cpp (c) 2023
  Desc: Power of Four
  Created:  Sun Oct 23 2023 21:19:48 GMT+0530 (India Standard Time)
*/


/*Question: Given an integer n, return true if it is a power of four. Otherwise, return false.
An integer n is a power of four, if there exists an integer x such that n == 4x.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)return false;
        else{
            float x= log2(n)/2;
            if(x==(int)x) return true;
            else return false;
        }
    }
};

// APPROACH: 
// 1. If n is zero or negative return false.
// 2. Else calculate the power using formula and store it into a float type variable.
// 3. Check if it is an integer value return true,if not return false.

// Time Complexity: O(1)
// Space Complxity: O(1)
