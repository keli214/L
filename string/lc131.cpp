#include <vector>
#include <iostream>
using namespace std;
/*
    Using dp to store whether a substring is a palindrome
    dp[i][j]: if s[i-j] is a palindrome
*/

void backtrack(string s, vector<vector<bool>>& dp, int r, vector<string>& curr, vector<vector<string>>& res){
    for(int j = r; j < s.size(); j++){
        if(dp[r][j]){
            curr.push_back(s.substr(r, j-r+1));
            if(j == s.size()-1){
                res.push_back(curr);
            }
            backtrack(s, dp, j+1, curr, res);
            curr.pop_back();
        }
    }
}


vector<vector<string>> partition(string s) {
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), true));
    vector<vector<string>> res;
    for(int i = 0; i < s.size(); i++){
        for(int j = i; j < s.size(); j++){
            string curr = s.substr(i, j-i+1);
            int n = curr.size();
            for(int k = 0; k < n/2; k ++){
                if( curr[k] != curr[n-1-k]){
                    dp[i][j] = false;
                    break;
                }
            }
        }
    }
    vector<string> curr;
    backtrack(s, dp, 0, curr,res);
    return res;
}

int main(){
    string s {"aab"};
    auto res = partition(s);
    for(auto s: res){
        for(auto p: s){
            cout<<p<<" ";
        }
        cout<<endl;
    }
}