/*
Author: Purnendu Tudu (purnendu2udu@gmail.com)
q217.cpp (c) 2023
Desc: Two Sum
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> checks;
        for(int i = 0 ; i < nums.size() ; i++){            
            int toSearch = target - nums[i];
            if(checks.find(toSearch) != checks.end()){
                //cout <<  checks[toSearch] << i << endl;
                return {checks[toSearch] , i};
            }
            checks.insert({nums[i], i});
            
        };
        return {0,0};
        
    }
};

/*
 Link : https://leetcode.com/problems/two-sum/description/
 Question :Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
           You may assume that each input would have exactly one solution, and you may not use the same element twice.
 Approach: Approach is so simple and easy
 [1] take an unordered map.
 [2] iterate  through the 'nums'.
 [3] we store the complement of the target by subtracting it from the nums. 
     toSearch = target - nums[i]
 [4] now we check if the complement exist on the unordered_map. 
 [5] if exisit the we return the value from the unordered_map. Here our key is the [toSearch].
     and the index value of that num which give us the key.
 [6] if not exisit we simply add the num and its index is (key, value) pair.
 [7] if no solution is found we simple return {0,0}
  

  Time Complexity: O(n).
  Space Complexity : O(n).
*/
