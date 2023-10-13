/*
Author: Purnendu Tudu (purnendu2udu@gmail.com)
q242.cpp (c) 2023
Desc: Valid Anagram
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> firstString;
        std::unordered_map<char, int> secondString;
        for(char character : s){
            if(firstString.find(character) != firstString.end()){
                firstString[character]++;
            }else{
                firstString[character] = 1;
            }
        }
        for(char character : t){
            if(secondString.find(character) != secondString.end()){
                secondString[character]++;
            }else{
                secondString[character] = 1;
            }
        }

        return firstString == secondString;

        
    }
};

/*
 Link : https://leetcode.com/problems/valid-anagram/
 Question :Given two strings s and t, return true if t is an anagram of s, and false otherwise.An Anagram is a word or phrase 
           formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once..
 Approach:
    [0] Approach is so simple. Here I have used the (key, value) pair concept.
        Look at this Input: s = "anagram", t = "nagaram".
        If we break down the string 's' we will find that 
          No of 'a' present in the string is = 3,
          No of 'n' present in the string is = 1,
          No of 'g' present in the string is = 1,
          No of 'r' present in the string is = 1,
          No of 'm' present in the string is = 1.
        No if the sting 't' has the same frequence of the chracters then 
        we will get our anagram.
   [1] Create two empty map for string 's' and 't'.
   [2] Scan all the characters and store it in the map.
   [3] During the scan if the character appera more than one increase the value of it.
   [4] After scaning done check if those two map are same.
   [5] If Same return True Else Return false.

  Time Complexity: O(n).
  Space Complexity : O(n).
*/
