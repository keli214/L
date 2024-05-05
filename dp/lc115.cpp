#include <string>
#include <vector>
#include <iostream>

using namespace std;

int numDistinct(string s, string t){
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1, vector(m+1, 0));
    dp[0][0] = 1;
    for(auto &r: dp){
        r[0] = 1;
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m ; ++j){
            int notTaken = dp[i-1][j];
            
            int taken = s[i-1]==t[j-1] ? dp[i-1][j-1] : 0;
    
            dp[i][j] = taken + notTaken;
        }
    }
    
    for(auto r: dp){
        for(auto c: r){
            cout<<c<<" ";
        }
        cout<<endl;
    }
    return dp[n][m];
}

int main(){
    string s = "babgbag", t = "bag";
    cout<<numDistinct(s, t);
}