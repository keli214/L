#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

/*
    BF: backtrack to find test all the possible combinations
*/
// int res = 0;
// void backtrack(int n, int i, bool includeA, int endsL){
//     if(i == n){
//         res++;
//         return;
//     }
//     //add P
//     backtrack(n, i+1, includeA, 0);
//     if(!includeA){
//         //add A
//         backtrack(n, i+1, true, 0);
//     }
//     if(endsL != 2){
//         //add L
//         backtrack(n, i+1, includeA, endsL+1);
//     }
// }

int checkRecord(int n) {
    int m = 1000000007;
    vector<vector<int>> dp(3, vector<int>(n, 0));
    
    //p
    dp[0][0] = 1;
    //a
    dp[1][0] = 1;
    dp[1][1] = 2;
    dp[1][2] = 4;
    //l
    dp[2][0] = 1;
    dp[2][1] = 3;

    
    if(n == 1) return 3;
    
    for(int i = 1; i < n; i++)
    {
        dp[0][i - 1] %= m;
        dp[1][i - 1] %= m;
        dp[2][i - 1] %= m;
        //add P at the end
        dp[0][i] = ((dp[0][i - 1] + dp[1][i - 1]) % m + dp[2][i - 1]) % m;
        //add A at the end
        if(i > 2) dp[1][i] = ((dp[1][i - 1] + dp[1][i - 2]) % m + dp[1][i - 3]) % m;
        //add L at the end
        if(i > 1) dp[2][i] = ((dp[0][i-1] + dp[1][i-1]) % m + (dp[0][i-2] + dp[1][i-2]) % m) % m;
    }
    
    return ((dp[0][n - 1] % m + dp[1][n - 1] % m) % m + dp[2][n - 1] % m) % m;
    
}

int main(){
    cout<<checkRecord(3);
}