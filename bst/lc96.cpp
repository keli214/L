#include <iostream>

using namespace std;
/*
    The number of BST with root being element i is the product of 
    numTrees(i-1) and numTrees(n-i), the total num of BST with n nodes 
    will the sum of BST with i ~ ( 1, n).
*/
int dp[20]{};
int numTrees(int n) {
    if(n <= 1)
        return 1;
    if(dp[n])
        return dp[n];
    for(int i = 1; i <= n; i++){
        dp[n] += numTrees(i-1) * numTrees(n-i);
    }
    return dp[n];
}

int main(){
    int n = 3;
    cout<< numTrees(n);
}