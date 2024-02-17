#include <iostream>
#include <vector>

using namespace std;

bool canCross(vector<int>& stones) {
    /*  
        i: idx of the stone in the input, j = units of prev jump
        dp[i][j] = 1 if u can jump to i with k = j
        at each i, update the dp[j][k] where stones[j] is in the range of [stones[i] + k-1, stones[i] + k+1]
    */
    int n = stones.size(), maxK = stones.size();
    vector<vector<int>> dp(n, vector<int>(maxK, 0));
    //base case
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int k = 1; k <= maxK; k++){
            if(dp[i][k-1]){
                int distMax = stones[i] + k + 1 , distMin = stones[i] + k -1;
                //edge case where the first jump must be 1 unit
                if(i == 0)
                    distMax = stones[i] + 1;
                for(int j = i+1; j < stones.size(); j++){
                    if(stones[j] >= distMin && stones[j] <= distMax){
                        int nextK = stones[j]-stones[i];
                        dp[j][nextK-1] = 1;
                    }
                    if(stones[j] > distMax)
                        break;
                }
            }
        }
    }
    for(auto i: dp[n-1]){
        if(i)
            return true;
    }
    return false;
}   

int main(){
    vector<int> stones {0,1,3,6,10,15,16,21};
    // vector<int> stones {0,2};
    cout<<canCross(stones);
    return 0;
}