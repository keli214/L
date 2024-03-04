#include <string>
#include <iostream>

using namespace std;

bool isMatch(string s, string p) {
    /* dp[i][j] : whether s[:i] & p[:j] is the same
        at s[i] and p[j], there can be 4 cases:
            1) s[i] == p[j] 
                dp[i][j] = dp[i-1][j-1]
            2) p[j] == '?'
                dp[i][j] = dp[i-1][j-1]
            3) p[j] == '*'
                dp[i][j] = dp[i][j-1] | dp[i-1][j]
            4) s[i] != p[j]
                dp[i][j] = 0
    */    
    int n = s.size(), m = p.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    dp[0][0] = 1;
    for(int j = 1; j <= m; j++){
        if(p[j-1] == '*'){
            dp[0][j] = dp[0][j-1];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(p[j-1] == s[i-1])
                dp[i][j] = dp[i][j] || dp[i-1][j-1];
            if(p[j-1] == '?')
                dp[i][j] = dp[i][j] || dp[i-1][j-1];
            if(p[j-1] == '*')
                dp[i][j] = dp[i][j] || dp[i-1][j] || dp[i][j-1];
        }
    }
    return dp[n][m];
}

int main(){
    string s = "cb", p = "?a";
    cout<<isMatch(s, p);
}


