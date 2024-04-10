#include <vector>
#include <iostream>

using namespace std;

/*
    Brutal force: 
        set each number in arr as the begin of the new turbulence array
*/
int maxTurbulenceSize(vector<int>& arr) {
    int res = 1;
    int i = 0;
    while(i < arr.size()){
        int a = i, b = i+1, sign = -1;
        while(b < arr.size() && arr[a] != arr[b] && (sign == -1 || (arr[a] < arr[b] && sign) || (arr[a] > arr[b] && !sign))){
            sign = arr[a] > arr[b] ? 1 : 0;
            a++;
            b++;
        }
        res = max(res, b-i);
        i = a > i ? a : b;
    }
    return res;
}

int main(){
    vector<int> nums{9,9};
    cout<<maxTurbulenceSize(nums);
}