#include <iostream>
#include <vector>
#include <stack>
#include <numeric>

using namespace std;
/*
    Detecting the edge that is introducing a cycle into the graph
    Sol: 
        1. For each edge in edges Do a DFS after adding it to the graph
            DFS: keep visited nodes in a visited array, cycle occurs when the 
            if we came across an edge that result in a cycle 
            return that edge 
        2. Union Find: implement a disjoint set union(DSU) data structure
            keep a parent vector array. The representative of a set is the node 
            with its parent as itself
*/

class DSU{
    vector<int> par;
public:
    DSU(int n): par(n){
        iota (std::begin(par), std::end(par), 0);
    };
    int find(int x){
        if(par[x] == x){
            return x;
        }
        return find(par[x]);
    }
    bool Union(int x, int y){
        int xP = find(x);
        int yP = find(y);
        if(xP == yP) return false; //same set already
        return par[xP] = yP;
    }
};

bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr, int parent){
    if(visited[curr]) return true;
    visited[curr] = true;
    for(auto n: graph[curr]){
        if(n != parent && dfs(graph, visited, n, curr)){
            return true;
        }
    }
    return false;
}
// DFS
// vector<int> findRedundantConnection(vector<vector<int>>& edges){
//     int n = edges.size();
//     vector<vector<int>> graph(n+1);
//     for(auto e: edges){
//         graph[e[0]].push_back(e[1]);
//         graph[e[1]].push_back(e[0]);
//         vector<bool> visited(n+1, false);
//         if(dfs(graph, visited, e[0], 0)){
//             return e;
//         }
//     }
//     return {};
// }

vector<int> findRedundantConnection(vector<vector<int>>& edges){
    int n = edges.size();
    DSU d(n + 1);
    for(auto e: edges){
        if(!d.Union(e[0], e[1])){
            return e;
        }
    }
    return {};
}


int main(){
    vector<vector<int>> edges {{1,2},{1,3},{2,3}};
    vector<int> res = findRedundantConnection(edges);
    cout<<res[0]<<" "<<res[1]<<endl;
}