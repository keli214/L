#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
    int n = grid.size(), m = n-2;
    vector<vector<int>> res(m, vector<int>(m, INT_MIN));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            int maxLocal = INT_MIN;
            for(int f = 0; f <= 8; f++){
                int r = i + f/3, c = j + f%3;
                maxLocal = max(maxLocal, grid[r][c]);
            }
            res[i][j] = maxLocal;
        }
    }
    return res;
}

int main(){
    vector<vector<int>> grid{{9,9,8,1},{5,6,2,6},{8,2,6,4},{6,2,2,2}};
    auto res = largestLocal(grid);
    for(auto r: res){
        for(auto i: r){
            cout<<i<<" ";
        }
        cout<<endl;
    }

}