#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

vector<int> grayCode(int n) {
    vector<int> res;
    for(int i = 0; i < (1<<n); i++){
        res.push_back(i ^ (i>>1));
    }
    return res;
}

int main(){
    int n = 2;
    vector<int> res = grayCode(n);
    for(int i: res){
        cout<<i<<" ";
    }
    return 0;
}