/*Author: Sk Firoj(sk.firoj9732@gmail.com)
  q283.cpp (c) 2023
  Desc: Move Zeroes
  Created:  Sun Oct 22 2023 19:40:48 GMT+0530 (India Standard Time)
*/

/*Question: Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
         int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[j]=nums[i];
                j++;
            }
        }
        for(int i=j;i<nums.size();i++){
            nums[i]=0;
        }        
    }
};

// APPROACH
// 1. Iterate through the array and place the non zero elements from left of the same array using two pointer approach.
// 2. After placing all the non-zero elements in the array fill the remaining indices with zeros.

// Time Complexity: O(n)
// Space Complexity: O(1)
