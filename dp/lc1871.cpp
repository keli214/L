#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
    can only jump to j if j is in the range and s[j] = 0
    using dp to test if we can reach j and slide window to 
    avoid checking the entire window
*/

bool canReach(string s, int minJump, int maxJump) {
    int n = s.size(), prev = 0;
    vector<int>dp(n, 0);
    dp[0] = 1;
    for(int i = 1; i < n; i++){
        if(i-minJump >= 0 ){
            prev += dp[i-minJump];
        }
        if(i-maxJump >= 0){
            prev -= dp[i-maxJump-1];
        }
        dp[i] = prev > 0 && s[i] == '0';
    }
    return dp[n-1];
}

int main(){
    string s = "011010";
    int minJ = 2, maxJ = 3;
    cout<<canReach(s, minJ, maxJ);
}

