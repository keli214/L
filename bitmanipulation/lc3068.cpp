#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

long long maxSum = 0;

/*
    Given the graph is a tree, all the nodes are connected in G
    thus we can choose any two nodes from G and perform the xor 
    operation because xor a number twice result in the num itself.
    a - b - c : a^k - b^k^k - c^k : a^k - b - c^k
    therefore we just need to find the nodes that will result in a
    greater num after xor and form even pairs
    If we have odd num of such nodes, pick a node that result in the
    smallest negative diff and see if that's less than pos diff
*/
long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
    long long currSum = 0ll;
    int minPos = numeric_limits<int>::max(), minNeg = numeric_limits<int>::max();
    int numPos = 0;
    for(auto i: nums){
        currSum += i;
        int diff = (i ^ k) - i;
        if(diff > 0){
            numPos ++;
            currSum += diff;
            minPos = min(minPos, diff);
        } 
        else{
            minNeg = min(minNeg, abs(diff));
        }
    }
    if(numPos % 2 == 0){
        return currSum;
    }
    if(minPos > minNeg){
        return currSum - minNeg;
    }
    return currSum - minPos;
}

int main(){
    vector<int> nums{24,78,1,97,44};
    int k = 3;
    vector<vector<int>> edges{{0,2},{1,2},{4,2},{3,4}};
    auto res = maximumValueSum(nums, k, edges);
    cout<<res;
}