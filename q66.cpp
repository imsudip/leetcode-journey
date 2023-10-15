/*
Author: Ivy Kumbhakar (ivykumbhakar855@gmail.com)
q66.cpp (c) 2023
Desc: Plus One
Created:  Sun Oct 15 2023 12:46:32 GMT+0530 (India Standard Time)
*/


/* QUESTION :
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. 
The large integer does not contain any leading 0's. Increment the large integer by one and return the resulting array of digits.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
vector<int> plusOne(vector<int>& digits) {
    int n;
    for(n=(digits.size()-1);n>=0;n--){
        if(digits[n]!=9){
            digits[n]++;
            break;
        }
        else{
            digits[n]=0;
        }
    }
    if(n==-1){
        digits.insert(digits.begin(),1);
    }
    return digits;
}
};

/*APPROACH:
  1. Iterate the array digits from the last and check if the element is 9 or not.
  2. If the element is less than 9 then add one with the element and break the loop.
  3. Otherwise make the element 0 and continue iterating.
  4. If the loop complete all the ietration(that means all the elements in array are 9),then insert 1 at the begining of the array.
  5. Return digits.

  TIME COMPLEXITY: O(n)
  SPACE COMPLEXITY: O(1)

  */
