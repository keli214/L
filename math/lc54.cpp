#include <vector>
#include <iostream>

using namespace std;

int dir[5] = {0,1,0,-1,0};
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int r = 0, c = 0, count = 0, n = matrix.size(), m = matrix[0].size(), d = 0, l = 0, currC = m, currR = n-1, curr = currC;
    vector<int> res;
    while(count < n*m){
        // cout<<r<<c<<endl;
        res.push_back(matrix[r][c]);
        count ++;
        l++;
        //need to change dir
        if(l == curr){
            //row 
            if(d%2==0){
                currC --;
                curr = currR;
            }else{
                currR --;
                curr = currC;
            }
            d = (d + 1)%4;
            l = 0;
            // cout<<curr<<endl;
        }
        r += dir[d];
        c += dir[d + 1];
        
    }
    return res;
}

int main(){
    vector<vector<int>> m{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    auto res = spiralOrder(m);
    for(auto i: res){
        cout<<i;
    }
    
}