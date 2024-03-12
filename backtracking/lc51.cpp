#include <vector>
#include <string>
#include <iostream>

using namespace std;
/*
    Helper function to check if a board configuration is a valid solution
    after placing a queen at (i, j)
*/
bool isValid(vector<string> board, int i, int j){
    //col
    for(int r = 0; r < board.size(); r++){
        if(board[r][j] != '.'){
            return false;
        }
    }
    //diagonal
    int diag[5] {-1,-1,1,1,-1};
    for(int d = 0; d < 4; d++){
        int r = i+diag[d], c = j+diag[d+1];
        while( r >= 0 && r < board.size() && c >= 0 && c < board[r].size()){
            if(board[r][c] != '.')
                return false;
            r+=diag[d];
            c+=diag[d+1];
        }
    }
    return true;
}   

void helper(vector<vector<string>>& valid, vector<string>& curr, int n, int r){
    if(r == n) {
        valid.emplace_back(curr);
        return;
    }
    for(int j = 0; j < n; j++){
        if(isValid(curr,r,j)){
            curr[r][j] = 'Q';
            helper(valid, curr, n, r+1);
            curr[r][j] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> valid;
    vector<string> curr(n, string(n,'.'));
    helper(valid, curr, n, 0);
    return valid;
}

int main(){
    vector<vector<string>> res = solveNQueens(5);
    for(auto b: res){
        for(auto r: b){
            cout<<r<<endl;
        }
        cout<<endl;
    }
    cout<<res.size();
}