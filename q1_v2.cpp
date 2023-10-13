/*Author: Sk Firoj (sk.firoj9732@gmail.com)
Desc: Two sum*/

/* Question: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> cpy;
      cpy=nums;
      vector<int> ret;
      sort(nums.begin(),nums.end());
      int i=0,tosearch,idx=-1;
      for(i=0;i<nums.size();i++){
          tosearch=target-nums[i];
          idx=lower_bound(nums.begin()+i+1,nums.end(),tosearch)-nums.begin();
          if(idx>=0&&idx<nums.size()&&nums[i]+nums[idx]==target){
            break;
          }  
      }
      for(int k=0;k<cpy.size();k++){
          if(nums[i]==cpy[k]) ret.push_back(k);
          else if(nums[idx]==cpy[k]) ret.push_back(k);
      }
      return ret;
    }
};

// 1. Take a extra vector named cpy and copy the original vector into cpy.
// 2. Sort nums.
// 3. Calculate tosearch(target-nums[i]) for each element and find the tosearch using lower_bound.
// 4. If found exit from the loop.
// 5. Search for the original index of the tosearch & nums[i] and store the index in ret vector.
// 6. Return ret vector.

// Time Complexity= O(nlogn) 
// Space Complexity= O(n)
