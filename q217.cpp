/*
Author: Purnendu Tudu (purnendu2udu@gmail.com)
q217.cpp (c) 2023
Desc: Contains Duplicate
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std:unordered_set<int> check;
        for(int num : nums){
            if(check.count(num) > 0){
                return true;
            }else{
                check.insert(num);
            }
        }
        return false;

        
    }
};

/*
 Link : https://leetcode.com/problems/contains-duplicate/
 Question :Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
 Approach:
  1. Take an empty unordered set which store all the unique element from the input.
  2. Take one number from the nums and see if it exists in the 'check'.
  3. If  the num already exists return true.
  4. Else insert the number in the 'check'.
  5. In the loop if no duplicates is found we simply return false.

  Time Complexity: O(n).
  Space Complexity : O(n).
*/
