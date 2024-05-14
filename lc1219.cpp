#include <vector>
#include <iostream>

using namespace std;

/*
    BF: using a DFS to find the max from all possible path
    DP: store the number of
*/
int nei[5] = {-1,0,1,0,-1};
int dfs(vector<vector<int>>& grid, int r, int c){
    if(r >= grid.size() || r < 0 || c >= grid[r].size() || c < 0 || grid[r][c] == 0){
        return 0;
    }
    int temp = grid[r][c];
    int maxGold = 0;
    grid[r][c] = 0;
    for(int d = 0; d < 4; d++){
        int i = r + nei[d], j = c + nei[d+1];
        maxGold = max(maxGold, dfs(grid, i, j));
    }
    grid[r][c] = temp;
    return maxGold + grid[r][c];
}
int getMaximumGold(vector<vector<int>>& grid) {
    int res = 0;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            res = max(res, dfs(grid, i, j));
        }
    }
    return res;
}


int main(){
    vector<vector<int>> grid{{0,6,0},{5,8,7},{0,9,0}};
    cout<<getMaximumGold(grid);
}