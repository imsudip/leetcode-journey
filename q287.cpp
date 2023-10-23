/*
Author: Abdul Kadir  (abdulkadir.co21d2@scet.ac.in)
q287.cpp (c) 2023
Desc: Finding the Duplicate Number 
Created: Mon at Oct 23 2023 18:26:10 GMT+0530 (India Standard Time)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> v=nums;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]==v[i+1])
                return v[i];
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> v={1,2,3,4,4,5,6,7,8};
    cout<<s.findDuplicate(v)<<"\n";
    return 0;
}


// Approach
/*
    Here we have to find the number which appears 2 times in the given array/vector
    So firstly I have sorted the given vector using the inbuilt sort function of C++ 
    and then traversed the vector where I check two neighbouring elements and if they are same
    return that element, the reasoning being that same element after sorting will appear adjacent to each otehr
*/
// Time Complexity: O(n*log(n))
// Space Complexity: O(n)
// n is size of vector/array