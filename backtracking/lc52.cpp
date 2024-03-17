#include <vector>
#include <iostream>

using namespace std;

bool isValid(vector<vector<char>>& board, int i, int j){
    //col
    for(int r = 0; r < board.size(); r++){
        if(board[r][j] != '.'){
            return false;
        }
    }
    //diagonal
    int dir [5] = {-1, -1, 1, 1, -1};
    for(int d = 0; d < 4; d++){
        int r = i+dir[d], c = j+dir[d+1];
        while(r >= 0 && r < board.size() && c >= 0 && c < board.size()){
            if(board[r][c] != '.'){
                return false;
            }
            r += dir[d];
            c += dir[d+1];
        }
    }
    return true;
}

void helper(vector<vector<char>>& board, int& res, int i){
    if(i == board.size()){
        res ++;
        return;
    }
    for(int c = 0; c < board[i].size(); c++){
        if(isValid(board, i, c)){
            board[i][c] = 'Q';
            helper(board, res, i+1);
            board[i][c] = '.';
        }
    }
}

int totalNQueens(int n) {
    int res = 0;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    helper(board, res, 0);
    return res;
}

int main(){
    cout<<totalNQueens(4);
}