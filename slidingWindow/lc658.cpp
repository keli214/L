#include <vector>
#include <iostream>

using namespace std;
/*
    Given a sorted integer array arr, two integers k and x, 
    return the k closest integers to x in the array. 
    The result should also be sorted in ascending order.

    find the diff for the first k elements in arr, 
    update the diff as the window slides
    
*/
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int l = 0, r = k-1, minDiff = 0;
    for(int i = 0; i < k; i++){
        minDiff += abs(arr[i]-x);
    }
    
    int currDiff = minDiff;
    for(int i = k; i < arr.size(); i++){
        
        currDiff += abs(arr[i]-x);
        currDiff -= abs(arr[i-k]-x);

        // cout<<i<<' '<<currDiff<<endl;
        if(currDiff < minDiff){
            minDiff = currDiff;
            r = i;
            l = r-k+1;
        }
    }
    vector<int> res(arr.begin()+l, arr.begin()+r+1);
    return res;
}

int main(){
    vector<int> arr {0,0,0,1,3,5,6,7,8,8};
    int k = 2, x = 2;
    vector<int> res = findClosestElements(arr, k, x);
    for(auto i: res){
        cout<<i<<' ';
    } 
    return 0;
}