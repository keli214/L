#include <vector>
#include <iostream>
#include <queue>

using namespace std;
/*
You are given two m x n binary matrices grid1 and grid2 
containing only 0's (representing water) and 1's (representing land). 

An island is a group of 1's connected 4-directionally (horizontal or vertical). 
Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 
that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.

*/
int nei[5] = {-1, 0, 1, 0, -1};
/*
    Solution: do a BFS in grid2, whenever check a new land cell in grid2 if it's not a land in grid1
    mark it as non sub-island.
    If we encounter a non sub-island, skip the rest of the cells?
    Mark visited cell as -1.
*/
int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int res = 0;
    for(int i = 0; i < grid2.size(); i++){
        for(int j = 0; j < grid2[i].size(); j++){
            //encounter land cell that haven't visited
            if(grid2[i][j] == 1){
                bool subIsland = true;
                queue<pair<int,int>> q;
                grid2[i][j] = -1;
                q.push({i,j});
                while(!q.empty()){
                    auto curr = q.front();
                    q.pop();
                    int r = curr.first, c = curr.second;
                    if(grid1[r][c] != 1){
                        subIsland = false;
                    }
                    //check all the nei cells
                    for(int d = 0; d < 4; d ++){
                        int nR = r + nei[d], nC = c + nei[d+1];
                        if(nR >= 0 && nR < grid2.size() && nC >= 0 && nC < grid2[nR].size() && grid2[nR][nC] == 1){
                            //mark it as visited
                            grid2[nR][nC] = -1;
                            q.push({nR,nC});
                        }
                    }
                }
                if(subIsland){
                    res++;
                }
            }
        }
    }
    return res;
}

int main(){
    vector<vector<int>> grid1 = {{1,0,1,0,1},{1,1,1,1,1},{0,0,0,0,0},{1,1,1,1,1},{1,0,1,0,1}}, 
                        grid2 = {{0,0,0,0,0},{1,1,1,1,1},{0,1,0,1,0},{0,1,0,1,0},{1,0,0,0,1}};

    cout<<countSubIslands(grid1, grid2);

}