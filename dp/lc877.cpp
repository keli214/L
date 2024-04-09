#include <vector>
#include <iostream>

using namespace std;

vector<vector<pair<int, int>>> dp;

int helper(vector<int>& piles, int id, int l, int h){
    if(l > h){
        return 0;
    }
    if(id == 1 && dp[l][h].first != -1){
        return dp[l][h].first;
    }
    else if(id == 2 && dp[l][h].second != -1){
        return dp[l][h].second;
    }

    int next = id == 1 ? 2 : 1;

    if(id == 1){
        dp[l][h].first = max(piles[l] + helper(piles, next, l+1, h), piles[h] + helper(piles, next, l, h-1));
    }
    else{
        dp[l][h].second = min(-piles[l] + helper(piles, next, l+1, h), -piles[h] + helper(piles, next, l, h-1));
    }

    return id == 1 ? dp[l][h].first : dp[l][h].second ;

}
/*
    If the first player will win 
    Each round has 4 possibilities: 
        1) alice first, bob last
        2) alice first, bob sec
        3) alice last, bob first
        4) alice last, bob sec to last
    
    we can have a dp[n+1][n+1][id] for the score at each round
    where dp[i][j][id] is the optimal score of the round where id(1 for alice, 2 for bob)
    picked from piles[i-j] and score is the difference between the points of
    alice and bob. 

*/

bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    for(int i = 0; i <= n; i ++){
        dp.push_back(vector<pair<int,int>>(n+1, {-1,-1}));
    }
    return helper(piles, 1, 0, piles.size()-1) >= 0;
}

int main(){
    vector<int> piles{3,7,2,3};
    cout<<stoneGame(piles);
}