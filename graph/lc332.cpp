#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
unordered_map<string, vector<string>> adj;
vector<string> res;
void dfs(string curr){
    while(adj[curr].size()){
        //check all the tickets that starts from curr
        string next = *(adj[curr].begin());
        adj[curr].erase(adj[curr].begin());
        dfs(next);
    }
    res.push_back(curr);
}
/*
    1. construct an adjacency list 
    
*/
vector<string> findItinerary(vector<vector<string>>& tickets) {

    for(auto t: tickets){
        adj[t[0]].emplace_back(t[1]);
    }
    //sort the edges
    for(auto &d: adj){
        sort(d.second.begin(), d.second.end());
    }
    string start = "JFK";
    dfs(start);
    return vector<string>(res.rbegin(), res.rend());
}


int main(){
    vector<vector<string>> tickets {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    vector<string> res = findItinerary(tickets);

    for(auto s: res){
        cout<<s<<" ";
    }

}