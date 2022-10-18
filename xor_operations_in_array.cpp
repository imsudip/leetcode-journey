// XOR operations in an array - https://leetcode.com/problems/xor-operation-in-an-array/
class Solution {
public:
    int xorOperation(int n, int start) {
        int nums[n], i, result = 0;
        
        // Storing the elements in array nums
        for(i = 0; i < n; i++) {
          nums[i] = start + 2 * i;
        }
        
        // Storing the resultant value in result
        for(i = 0; i < n; i++) {
           result = result ^ nums[i]; 
        }
        return result;
    }
};