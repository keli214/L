#include <vector>
#include <iostream>

using namespace std;
int nei[5] = {-1,0,1,0,-1};
vector<vector<int>> dp;

int helper(vector<vector<int>>& matrix, int i, int j, int n, int m){
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    dp[i][j] = 1; 
    for(int d = 0; d < 4; d++){
        int r = i + nei[d], c = j + nei[d+1];
        if(r >= 0 && r < n && c >= 0 && c < m && matrix[i][j] < matrix[r][c]){
            dp[i][j] = max(dp[i][j], 1 + helper(matrix, r, c, n, m));
        }
    }
    return dp[i][j];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size(), res = 1;
    for(int i = 0; i < n; i++){
        dp.push_back(vector<int>(m, -1));
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int currMax = 1;
            for(int d = 0; d < 4; d++){
                int r = i + nei[d], c = j + nei[d+1];
                if(r >= 0 && r < n && c >= 0 && c < m && matrix[i][j] < matrix[r][c]){
                    currMax = max(currMax, 1 + helper(matrix, r, c, n, m));
                }
            }
            res = max(res, currMax);
        }
    }    
    return res;
}

int main(){
    vector<vector<int>> matrix {{3,4,5},{3,2,6},{2,2,1}};
    cout<<longestIncreasingPath(matrix);
}