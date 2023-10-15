/* QUESTION :
   Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
       sort(nums1.begin(),nums1.end());
       sort(nums2.begin(),nums2.end());
       vector<int> ret;
       int j=0,k=0; 
       while(j<=(nums1.size()-1)&&k<=(nums2.size()-1)){
        if(nums1[j]<nums2[k]){
            j++;
        }
        else if(nums1[j]>nums2[k]){
           k++;
        }
        else{
           ret.push_back(nums1[j]);
           j++;
           k++;
        }
       }
        return ret;
    }

};

/*APPROACH :
  1. Sort both the array in ascending order and take an additional array 'ret'.
  2. take 2 pointer 'j' and 'k' for 'nums1' and 'nums2' respectively. Then iterate and check the element of those array.
  3. Increment 'j' if nums1[j]<nums2[k].
  4. Increment 'k' if nums2[k]<nums1[j].
  5. If nums1[j]==nums2[k] then push that element in 'ret' and increment both 'j' and 'k'.
  6.Return ret.

  TIME COMPLEXITY : O(m+n)
  SPACE COMPLEXITY : O(n)
*/
