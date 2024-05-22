#include <vector>
#include <numeric>
#include <iostream>
#include <queue>

using namespace std;

/*
    Given a tree with n nodes and a cost associated with one of them
    Assign coins to each node based on the number of children it has
    1. if there are less than 3 children, assign it as 1 
    2. else assign the max product of the cost of three distinct nodes in the 
    subtree(including the root)

    construct the tree graph first with unordered map
    select node 0 as the first node and keep a visited for DFS

    
*/
vector<long long> res;

vector<long long> dfs(vector<vector<int>>& g, 
                    vector<int>& visited, 
                    vector<int>& cost, 
                    int curr){
    vector<long long> nums;
    for(int n: g[curr]){
        if(!visited[n]){
            visited[n] = true;
            auto coins = dfs(g, visited, cost, n);
            for(auto c: coins){
                nums.push_back(c);
            }
        }
    }
    nums.push_back(cost[curr]);
    sort(nums.begin(), nums.end(), greater<int>());
    size_t n = nums.size();
    if(n < 3) 
        res[curr] = 1;
    else{
        long long front = nums[0] * nums[1] * nums[2], back = nums[n-1] * nums[n-2] * nums[0];
        long long maxNum = max(front, back);
        res[curr] = maxNum > 0 ? maxNum : 0;
    }
    if(n <= 5)
        return nums;
    return {nums[0], nums[1], nums[2], nums[n-1], nums[n-2]};
}

vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
    size_t n = cost.size();
    vector<vector<int>> g(n, vector<int>());
    for(auto e: edges){
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }
    vector<int> visited(n, false);
    res.resize(n);
    visited[0] = true;
    dfs(g,visited, cost, 0);
    return res;
}

int main(){
    vector<vector<int>> edges {{0,1},{0,2},{0,3},{0,4},{0,5}};
    vector<int> cost {1,2,3,4,5,6};
    auto res = placedCoins(edges, cost);
    for(auto i: res){
        cout<<i<<" ";
    }
}