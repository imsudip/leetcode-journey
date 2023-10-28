/*Author: Sk Firoj(sk.firoj9732@gmail.com)
  q1512.cpp (c) 2023
  Desc: Number of Good Pairs
  Created:  Sun Oct 22 2023 19:15:48 GMT+0530 (India Standard Time)
*/


/*Question: Given an array of integers nums, return the number of good pairs.
A pair (i, j) is called good if nums[i] == nums[j] and i < j.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int i=0,cnt=0,goodpair=0;
       while(i<nums.size()-1){
           if(nums[i]==nums[i+1]){
               cnt++;
               goodpair=goodpair+cnt;
           } 
           else{
               cnt=0; 
           }
           i++;
       } 
       return goodpair;
    }
};


// APPROACH: 
// 1. Sort the vector in ascending order.
// 2. Iterate the vector and check if nums[i]==nums[i+1], increment the counter and update the total no. of good pair.
// 3. if nums[i]!=nums[i+1], set the counter to zero.
// 4. After iterating the vector return goodpair.

// Time Complexity: O(nlogn)
// Space Complxity: O(1)
