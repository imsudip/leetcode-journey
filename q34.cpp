/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int mid=0,f=0,l=nums.size()-1,uindex=-1,lindex=-1;
        vector<int> v;
        if(nums.size()==1&&nums[0]==target){
            v.push_back(0);
            v.push_back(0);
            return v;
        }
        while(f<=l){
            mid=(f+l)/2;
            if(nums[mid]==target){
                lindex=mid;
                l=mid-1;
            }
            else if(nums[mid]>target){
                l=mid-1;
            }
            else{
                f=mid+1;
            }
        }
        f=0;
        l=nums.size()-1;
        while(f<=l){
            mid=(f+l)/2;
            if(nums[mid]==target){
                uindex=mid;
                f=mid+1;
            }
            else if(nums[mid]>target){
                l=mid-1;
            }
            else{
                f=mid+1;
            }
        }
        v.push_back(lindex);
        v.push_back(uindex);
        return v;

    }
};

//1. If vector has only one element and that element is target then return that as first and last index.
//2. Find the first occurance of the element using a modified binary search (lower_bound) and store the index (lindex).
//3. In the second while loop find the last occurance of the element using a modified binary search (upper_bound) and store the index (uindex).
//4. Store lindex and uindex in vector v and return it.
