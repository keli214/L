#include <vector>
#include <iostream>

using namespace std;

int dir[5] = {0,1,0,-1,0};
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int r = 0, c = 0, count = 0, n = matrix.size(), m = matrix[0].size();
    int d = 0, l = 0, currC = m, currR = n-1, curr = currC;//starting in the first row
    vector<int> res;
    while(count < n*m){
        res.push_back(matrix[r][c]);
        count ++;
        l++;
        //need to change dir
        if(l == curr){
            if(d%2==0){//going in a row  
                currC --;
                curr = currR;
            }else{//going in a col
                currR --;
                curr = currC;
            }
            d = (d + 1)%4;
            l = 0;
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