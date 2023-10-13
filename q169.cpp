/*Author: Sk Firoj (sk.firoj9732@gmail.com)
Desc: Majority Element*/


/* QUESTION: Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        sort(nums.begin(),nums.end());    
        return nums[(nums.size()-1)/2];
    }
};


// APPROACH: 
// 1. IF THERE IS ONLY ONE ELEMENT RETURN THE ELEMENT
// 2. SORT THE VECTOR NUMS
// 3. THE MAJORITY ELEMENT WILL BE IN THE MIDDLE POSITION OF THWE VECTOR AFTER SORTING
// 4. RETURN THE ELEMENT AT THE MID POSITION
// Time Complexity= O(nlogn) 
// Space Complexity= O(1)
