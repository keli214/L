#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

/*
    for each row, flip the row if the first bit is 0
    for each col, flip the col if 0s bits are more than 1s 
*/
void flip(vector<vector<int>>& grid, int idx, bool col){
    if(col){
        for(int i = 0; i < grid.size(); i++){
            grid[i][idx] = grid[i][idx] == 1 ? 0 : 1;
        }
    }
    else{
        for(int j = 0; j < grid[idx].size(); j++){
            grid[idx][j] = grid[idx][j] == 1 ? 0 : 1;
        }
    }
}

bool moreOnes(vector<vector<int>>& grid, int col){
    int n = grid.size(), test = 0;
    for(int i = 0; i < grid.size(); i++){
        test += grid[i][col];
    }
    return test > n/2;
}
int matrixScore(vector<vector<int>>& grid) {
    
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(j == 0){
                if(grid[i][j] == 0) flip(grid, i, false);
            }
            else{
                if(!moreOnes(grid, j)){
                    flip(grid, j, true);
                }   
            }
            
        }
    }
    int res = 0;
    for(auto r: grid){
        int curr = 0;
        for(int i: r){
            curr = curr*2 + i;
        }
        res += curr;
    }
    return res;
    
}

int main(){
    vector<vector<int>> grid{{0,0,1,1}, {1,0,1,0}, {1,1,0,0}};
    cout<<matrixScore(grid);
}