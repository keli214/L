#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;
/*
    BF: traverse throught the arr with 3 for loops to find the first tuple of 
    [i, j, k] such that arr[i] + arr[j] = arr[k]
    then search for the next tuple by setting next i' to j, j' to k 
    and find if there is a k such that arr[i'] + arr[j'] = arr[k]

    for each (i,j) pair, using the fact that the arr is sorted to
    do a binary search to find k 

*/
int helper(vector<int>& arr, int i, int j, int currLen, unordered_map<int, int>& m, vector<vector<int>>& dp){
    int t = arr[i] + arr[j];
    if(m.find(t) != m.end() && dp[i][j] == 0){
        dp[i][j] = 1;
        return helper(arr, j, m[t], currLen + 1, m, dp);
    }
    return currLen;
}

int lenLongestFibSubseq(vector<int>& arr) {
    int res = 2; 
    unordered_map<int, int> m;
    vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));
    for(int i = 0; i < arr.size(); ++i){
        m[arr[i]] = i;
    }
    for(int i = 0; i < arr.size()-2; ++i){
        for(int j = i+1; j < arr.size()-1; ++j){
            res = max(res, helper(arr, i, j, 2, m, dp));    
        }
    }
    return res > 2 ? res: 0;
}

int main(){
    vector<int> arr{1,2,3,4,5,6,7,8};
    cout<<lenLongestFibSubseq(arr);
}