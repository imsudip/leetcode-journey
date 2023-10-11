/*Author: Sk Firoj (sk.firoj9732@gmail.com)
Desc: First Bad Version*/

/* QUESTION: You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check.
Since each version is developed based on the previous version, all the versions after a bad version are also bad.
Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#include<bits/stdc++.h>
class Solution {
public:
    int firstBadVersion(int n) {
        int bad,f=1,l=n,mid;
        if(n==1 && isBadVersion(1)){
            return n;
        }
        while(f<=l){
            mid=f+((l-f)/2);
            if(isBadVersion(mid)){
                bad=mid;
                l=mid-1;
            }
            else if(!(isBadVersion(mid))){
                f=mid+1;
            }
        }
        return bad;
    }
};

// Approach:
// 1. If there is only one element in the vector and that is the bad element return n.
// 2. Use binary search to find a bad element using the given API.
// 3. If found, again search for another bad element toward the left of the previous bad element by reducing the search space.
// 4. Using this approach find the first bad element out of the vector.
// 5. Return bad.

// Time Complexity: O(logn)
// Space Complexity: O(1)
