#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPrefixes(vector<string>& words, string s) { 
        int ans = 0;
        for(int i = 0 ; i<words.size() ; i++){
            string element = words[i];
            int len = element.length();
            
            for(int j = 0 ; j<len ; j++){
               
                if(element[j] != s[j]){
                    break;      
                }     
                if(j==len-1){
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution n;
    vector <string> words={"a","b","c","ab","bc","abc"};
    string s="abc";
    cout<<n.countPrefixes(words,s);
}
