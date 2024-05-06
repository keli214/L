#include <vector>
#include <iostream>

using namespace std;

/*
    BF: using backtracking to find all possible combinations of coins and take the max
    Top down dp: keep a dp table where dp[i][j] stores the max number of coins from popping ballons
    from i to j

*/
int maxCoins(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    for(int i = 1; i <= n; i++){
        dp[i][i] =  nums[i-1] * nums[i] * nums[i+1];
    }
    for(int len = 1; len <= n; len ++){
        for(int l = 1; l <= n - len; l++){
            int r = l + len;
            for(int k = l; k <= r; k++){
                dp[l][r] = max(dp[l][r], dp[l][k-1] + nums[l-1]*nums[k]*nums[r+1] + dp[k+1][r]);
            }
        }
    }
    return dp[1][n];
}

int main(){
    vector<int> nums{3,1,5,8};
    cout<<maxCoins(nums);
}