#include <vector>
#include <iostream>
#include <queue>

using namespace std;

/*
    At the inital time step, push all of the rotten oranges to the queue
    Do a BSF until queue is empty
    Check the grid at the end for any fresh oranges 
    return the number of level of the bsf if all oranges are rotten
*/

using idx = pair<int,int>;
int nei[5] = {-1, 0, 1, 0, -1};
int orangesRotting(vector<vector<int>>& grid) {
    queue<idx> q;
    int m = grid.size(), n = grid[0].size();
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 2){
                q.push({i,j});
            }
        }
    }
    int time = -1;
    while(!q.empty()){
        int width = q.size();
        for(int i = 0; i < width; i++){
            auto curr = q.front();
            q.pop();
            for(int d = 0; d < 4; d++){
                int r = curr.first + nei[d], c = curr.second + nei[d+1];
                if( r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1){
                    q.push({r,c});
                    grid[r][c] = 2;
                } 
            }
        }
        time ++;
    }
    for(auto r: grid){
        for(auto c: r){
            if(c == 1){
                return -1;
            }
        }
    }
    return time;
}

int main(){
    vector<vector<int>> grid{{0,2}};
    cout<<orangesRotting(grid);
}