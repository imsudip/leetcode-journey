/*
Author: Arghya Baran Naskar (arghya.official@yahoo.com)
q7.cpp (c) 2023
Desc: Reverse Integer
Created: Sat Oct 21 2023 13:13:43 GMT+0530 (India Standard Time)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    int reverse(int x) {
        bool isNegative = x<0;
        x = abs(x);
        int rem;
        long long r = 0;
        while(x>0){
            rem = x % 10;
            r = r * 10 + rem;
            x = x / 10;
        }
        if(isNegative){
            r = (-1)*r;
            if(r < INT_MIN)
                return 0;
        }
        else if(r> INT_MAX)
            return 0;
        return r;
    }
};

int main(){
    Solution s;
    cout << s.reverse(1LL * INT_MAX + 5) << endl;
    return 0;
}

// question: Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Approach:
// After understanding the problem the first thing that popped up in my mind that I have to do something to stop bit overflow while reversing the number i.e. keeping the number withing the 32-bit interger range. Also I didn't want any hassle regarding the sign of the number so I thought I will use a boolean variable to store that info. After getting hold of the reversed number I converted it to the original sign. Then I will just have to check if the number is within the bounds of a 32 bit integer or not. If it is then just return the reversed number itself otherwise return 0.

// 1. first I have created a boolean variable to store the information about the sign of the original number.

// 2. Then I have taken the absolute value of the number.
// 3. I have created a long long r(in leetcode even a long variable consumes 8bytes so, that will work too) variable to store the reversed number.

// 4. then I have reversed the number by seperating 1 digit at a time by taking the remainder after dividing it by 10.

// 5. then multiply r with 10 and add the remainder to the result.

// 6. step 3 to 5 will continue in a loop while x > 0.

// 7. After I got hold of the reversed number. I converted it to the original number's sign.
// 8. Now if r<INT_MIN then return 0 else if original number is positive && r>INT_MAX then also return 0.

// 9. Else return the reversed number itself.
