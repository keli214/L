#include <iostream>
#include <vector>

using namespace std;
bool helper(vector<int>& arr, int i, int j, int k){
    int a = i > 0 ? arr[i-1]^arr[j-1] : arr[j-1],
        b = arr[j-1]^arr[k];
    if(a==b){
        cout<<i<<j<<k<<endl;
    }
    return a == b;
}
int countTriplets(vector<int>& arr) {
    int res = 0;
    vector<int> pre(arr.begin(), arr.end());
    for(int i = 1; i < pre.size(); i++){
        pre[i] ^= pre[i-1];
    }
    for(int i = 0; i < arr.size()-1; ++i){
        for(int j = i+1; j < arr.size(); ++j){
            //find k such that j^...^k == i^...^j-1 which means i^...^k == 0
            int t = i > 0 ? pre[i-1] ^ pre[j] : pre[j];
            if(t == 0){
                res += j-i;
            }
        }
    }
    return res;
}

int main(){
    vector<int> arr{2,3,1,6,7};
    cout<<countTriplets(arr);
}