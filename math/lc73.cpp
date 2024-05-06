#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;
/*
    We iterate through the matrix to search for zeros 
    get the index of the zero elements
    then interate through the matrix again to edit the rows and cols to zero
*/
void setZeroes(vector<vector<int>>& matrix) {
    //using a hash set to store the zero index
    unordered_set<int> rows, cols;
    int m = matrix.size(), n = matrix[0].size();
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 0){
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    for(auto r: rows){
        for(auto &i: matrix[r]){
            i = 0;
        }
    }
    for(auto c: cols){
        for(auto &r: matrix){
            r[c] = 0;
        }
    }
}


int main(){
    vector<vector<int>> matrix{{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeroes(matrix);
    for(auto r: matrix){
        for(auto c: r){
            cout<<c<<" ";
        }
        cout<<endl;
    }
}