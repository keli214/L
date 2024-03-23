#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

/*
    Given an adjacency list, find the the shortest path from node k to all the rest of the node, 
    if any node is unreachable, return -1
*/

using pii = pair<int, int>; //node, dist
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    //construct the adjacent list with a unordered_map
    unordered_map<int, vector<pii>> m;
    for(auto p: times){
        m[p[0]].push_back({p[1],p[2]}); //u,v,d
    }
    //build a distance list
    vector<int> dist(n, INT_MAX); //(0 ~ n-1)
    //set start node dist to 0
    dist[k-1] = 0; 

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({k, 0}); //starting node
    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        int u = curr.first, d = curr.second;
        //check all the nei of u
        for(auto p: m[u]){
            int v = p.first, newDist = d + p.second;
            //check if the dist if smaller
            if(newDist < dist[v-1]){
                dist[v-1] = newDist;
                pq.push({v,newDist});
            }
        }
    }
    int maxDist = INT_MIN;
    //find the max path dist
    for(auto d: dist){
        if(d == INT_MAX){
            return -1;
        }
        maxDist = max(maxDist, d);
    }
    return maxDist;
}

int main(){
    vector<vector<int>> times {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4, k = 2;
    cout<<networkDelayTime(times, n, k);
}