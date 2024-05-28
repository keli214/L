#include <iostream>
#include <vector>

using namespace std;

/*
    find the number of submatrices such that the sum of submatrix 
    is less than k
    keep the sum of submatrix [0-x][0-y] at (x,y)
    sum[x][y] = sum[x-1][y] + sum[x][y-1] - sum[x-1][y-1] + grid[x][y]

*/

int countSubmatrices(vector<vector<int>>& grid, int k) {
    int res = 0, n = grid.size(), m = grid[0].size();
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(j > 0 && i > 0)
                grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
            else if(i > 0 && j == 0)
                grid[i][j] += grid[i-1][j];
            else if(i == 0 && j > 0)
                grid[i][j] += grid[i][j-1];
            if(grid[i][j] <= k){
                res ++;
            }
        }
    }
    return res;
    
}

int main(){
    vector<vector<int>> grid {{7,7,10,9},{10,5,10,3}};
    cout<<countSubmatrices(grid, 54);
}