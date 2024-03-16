#include <vector>
#include <iostream>

using namespace std;

/*  Iterate through the matrix in a spiral, 
    dir = [right, down, left, up]
    The number of step in each dir follows the 
    pattern : n, n-1, n-1, n-2, n-2, ..., 1, 1
*/
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    int dir [8] = {0,1,0,-1,0};
    int r = 0, c = -1, step = n, d = 0, t = 1, num = 1;
    while(step > 0){
        for(int i = 0; i < step; i++){
            r += dir[d];
            c += dir[d+1];
            // cout<<r<<" "<<c<<endl;
            res[r][c] = num++;
        }
        if(t){
            step--;
            t = 0;
        }
        else
            t++;
        d = (d+1)%4;
    }
    for(auto r: res){
        for(auto i: r){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return res;
}

int main(){
    int n = 4;
    generateMatrix(n);
}