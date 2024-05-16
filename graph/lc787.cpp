#include <vector>
#include <queue>
#include <iostream>
using namespace std;
/*
    Using dijkstra to find the cheapest path from src to dst, 
    keep track the length of the path 
    return false when len > k
*/
using pii = pair<pair<int,int>,int>; //{city, len}, price
bool Compare(pii a, pii b){
    return a.second < b.second;
}
// int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    
//     auto compare = [](pii a, pii b){ return a.second > b.second;};
//     priority_queue<pii, vector<pii>, decltype(compare)> pq(compare);
//     vector<vector<pair<int,int>>> graph(n);
//     for(auto flight: flights){
//         graph[flight[0]].push_back({flight[1], flight[2]});
//     }
//     pq.push({{src,-1},0});
//     while(!pq.empty()){
//         auto curr = pq.top();
//         pq.pop();
//         int city = curr.first.first, 
//             len = curr.first.second, 
//             price = curr.second;
//         if (len > k)
//             continue;
//         if(city == dst)
//             return price;
//         for(auto e : graph[city]){
//             int nextCity = e.first, p = e.second;
//             int currPrice = price + p;
//             pq.push({{nextCity, len + 1}, currPrice});
//         }
//     }

//     return -1;

// }

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    // relax all edges k + 1 times to find path that has stops at most k
    for(int i = 0; i <= k; i++){
        //using tmp to store the curr ith stop dist
        vector<int> tmp(dist);
        for(auto e: flights){
            int city = e[0], nextCity = e[1], price = e[2];
            //update the lowest price to nextCity if the price of city in i-1 + edge price is lower
            if(dist[city] != INT_MAX && dist[city] + price < tmp[nextCity] ){
                tmp[nextCity] = dist[city] + price;
            }
        }
        dist = tmp;
    }
    return dist[dst] == INT_MAX ? -1 : dist[dst];

}

int main(){
    int n = 5, src = 0, dst = 2, k = 2;
    vector<vector<int>> flights {{0,1,5},{1,2,5},{0,3,2},{3,1,2},{1,4,1},{4,2,1}};
    cout<<findCheapestPrice(n, flights, src, dst, k);

}