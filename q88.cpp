/*
Author: Ivy Kumbhakar (ivykumbhakar855@gmail.com)
q88.cpp (c) 2023
Desc: Merge Sorted Array
Created:  Sun Oct 22 2023 20:09:32 GMT+0530 (India Standard Time)
*/

/*
QUESTION : You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order. The final sorted array should not be returned by the function, but instead be stored inside the array nums1.
To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int i=m-1,j=n-1,k=m+n-1;
       while(j>=0){
           if(i==-1&&j>=0){
               nums1[k]=nums2[j];
               j--;
           }
           else if(nums1[i]>nums2[j]){
               nums1[k]=nums1[i];
               i--;
           }
           else {
               nums1[k]=nums2[j];
               j--;
           }
           k--;
       }
    }
};

/*
APPROACH: 
1. Iterate nums1 (from index m-1) and nums2 from end and compare the elements ,place the greater element at the end of nums1(from index m+n-1).
2. If there is no element remaining in nums1 to compare then place all the elements of nums2 from right to left in  nums1.

TIME COMPLEXITY: O(m+n)
SPACE COMPLEXITY: O(1)
*/
