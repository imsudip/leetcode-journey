/*Author: Sk Firoj(sk.firoj9732@gmail.com)
  q121.cpp (c) 2023
  Desc: Best Time to Buy and Sell Stock
  Created:  Sat Oct 14 2023 23:13:48 GMT+0530 (India Standard Time)
*/



/*QUESTION:You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int minPrice=INT_MAX;
       int profit=0; 
       for (int i=0; i<prices.size();i++){
           minPrice=min(prices[i],minPrice);
           profit=max(prices[i]-minPrice,profit);
       }
       return profit;
    }
};


/* APPROACH: 
1. Initialize a variable named minPrice to INTMAX, where we will store the minimum price.
2. Iterate through the vector and find the minPrice between price[i] and minPrice using min function.
3. Calculate the profit in each iteration using minPrice and store the all time max profit in profit variable using max function.
4. After traversing the vector return the profit.

Time Complexity= O(n)
Space Complexity=O(1)
*/
