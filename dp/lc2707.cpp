#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;
/*
    Iterate through all substrings to find whether they exists in the dictionary
    Using dp to keep track of the min # of unused character in s[:i]
     i  j i  j
     012345678
    "leetscode"
 dp 0123456789
    0123056781
*/
int minExtraChar(string s, vector<string>& dictionary) {
    unordered_set<string> m(dictionary.begin(), dictionary.end());
    vector<int> dp(s.size() + 1);
    int n = s.size();
    for(int i = 1; i <= n; i++){
        dp[i] = i;
    }
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            string curr = s.substr(i, j-i+1);
            if(m.find(curr) != m.end()){
                //find the min of (dp[x] + i-(x))
                for(int x = 0; x < i+1; x++){
                    dp[j+1] = min(dp[j+1], dp[x]+(i-x));
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        dp[n] = min(dp[n], dp[i] + (n-i));
    }
    return dp[n];
}

int main(){
    string s = "dwmodizxvvbosxxw";
    vector<string> dic {"ox","lb","diz","gu","v","ksv","o","nuq","r","txhe","e","wmo","cehy","tskz","ds","kzbu"};
    cout<<minExtraChar(s, dic);
    return 0;
}