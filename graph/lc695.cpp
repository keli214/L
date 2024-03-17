#include <vector>
#include <iostream>
#include <queue>

using namespace std;

/*
    You are given an m x n binary matrix grid. 
    An island is a group of 1's (representing land) connected 
    4-directionally (horizontal or vertical.) 
    You may assume all four edges of the grid are surrounded by water.

    Return the maximum area of an island in grid. If there is no island, return 0.

    Using BFS to search throught the island if found one 
    mark cells that visited already as '*'
*/
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int res = 0;
    int nei[5] {-1,0,1,0,-1};
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(grid[i][j]==1){
                queue<pair<int,int>> q;
                grid[i][j] = -1;
                q.push({i,j});
                int currSize = 0;
                while(!q.empty()){
                    auto curr = q.front();
                    q.pop();
                    currSize ++;
                    for(int n = 0; n < 4; n++){
                        int r = curr.first + nei[n], c = curr.second + nei[n+1];
                        if(r >= 0 && r < grid.size() && c >= 0 && c < grid[r].size() && grid[r][c] == 1){
                            grid[r][c] = -1;
                            q.push({r,c});
                        }
                    }
                }
                res = max(res, currSize);
            }
        }
    }
    return res;
}

int main(){
    vector<vector<int>> grid = {{1,1,0,0,0},
                                {1,1,0,0,0},
                                {0,0,0,1,1},
                                {0,0,0,1,1}};
    cout<<maxAreaOfIsland(grid);
}