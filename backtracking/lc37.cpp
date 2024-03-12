#include <vector>
#include <iostream>
using namespace std;

/* 
    Helper function to check if board is valid after 
    board[i][j] is set to val
    check the row, col, and the square
*/
bool isValid(vector<vector<char>>& board, int i, int j, int val){
    //row
    for(int c = 0; c < board[i].size(); c++){
        if(board[i][c] != '.' && board[i][c]-'1' == val)
            return false;
    }
    //col
    for(int r = 0; r < board.size(); r++){
        if(board[r][j] != '.' && board[r][j]-'1' == val)
            return false;
    }
    //square
    int row = i-i%3, col = j-j%3;
    for(int r = 0; r < 3; r++){
        for(int c = 0; c < 3; c++){
            if(board[row+r][col+c] != '.' && board[row+r][col+c]-'1' == val)    
                return false;
        }
    }
    return true;
}

bool helper(vector<vector<char>>& board, int i, int j){
    if(i == 9) return true;
    if(j == 9) return helper(board, i+1, 0);
    if(board[i][j] != '.') return helper(board, i, j+1);
    
    for(int c = 0; c < 9; c++){
        if(isValid(board, i, j, c)){
            board[i][j] = '1' + c;
            if(helper(board, i, j+1)) return true;
            board[i][j] = '.';
        }
    }
    return false;
}
/* 
    Fill in a number and check if the sodoku is valid
*/
void solveSudoku(vector<vector<char>>& board) {
    helper(board, 0, 0);
}

int main(){
    vector<vector<char>> board {{'5','3','.','.','7','.','.','.','.'},
                                {'6','.','.','1','9','5','.','.','.'},
                                {'.','9','8','.','.','.','.','6','.'},
                                {'8','.','.','.','6','.','.','.','3'},
                                {'4','.','.','8','.','3','.','.','1'},
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','6','.','.','.','.','2','8','.'},
                                {'.','.','.','4','1','9','.','.','5'},
                                {'.','.','.','.','8','.','.','7','9'}};
    for(auto r: board){
        for(auto c: r){
            cout<<c<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    solveSudoku(board);
    for(auto r: board){
        for(auto c: r){
            cout<<c<<" ";
        }
        cout<<endl;
    }
}