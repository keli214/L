#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    //flip by the diagonal 
    int n = matrix.size(), m = matrix[0].size();
    for(int i = 0; i < n; i ++){
        for(int j = i+1; j < m; j ++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    //flip by the vertical axis
    for(auto &r: matrix){
        reverse(r.begin(), r.end());
    }
}

int main(){
    vector<vector<int>> m {{1,2,3},{4,5,6},{7,8,9}};
    rotate(m);
    for(auto r: m){
        for(auto i: r){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}