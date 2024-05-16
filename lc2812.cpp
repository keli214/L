#include <vector>
#include <iostream>
#include <queue>
#include <array>

using namespace std;

/*
    BF: find the local of all the theives
    using BFS to cal the safety factor (SF) of each cell from theives
    traveling from the theive cell, currSF = parentSF + 1
    Using dijkstra to travel from 0,0 to find the max SF path
    return the min SF of the path - 1 since theive SF started as 1
*/

int dist(vector<int> x, vector<int> y){
    return abs(x[0]-y[0]) + abs(x[1]-y[1]);
}
int nei[5] = {-1, 0, 1, 0, -1};


int maximumSafenessFactor(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    // find all the theives in the grid
    queue<array<int, 2>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j]){
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();
        for(int d = 0; d < 4; d++){
            int r = i + nei[d], c = j + nei[d+1];
            if(r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 0){
                grid[r][c] = grid[i][j] + 1;
                q.push({r,c});
            }
        }
    }
    auto compare = [](auto a, auto b){
        return a[2] < b[2];
    };
    priority_queue<array<int,3>, vector<array<int,3>>, decltype(compare)> pq(compare);
    int safe = grid[0][0];
    for(auto r: grid){
        for(auto i: r){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    pq.push({0,0,grid[0][0]});
    grid[0][0] = -1; //mark it as visited
    while(!pq.empty()){
        auto [i,j,s] = pq.top();
        pq.pop();
        safe = min(safe, s);
        cout<<i<<j<<s<<endl;
        if(i == n-1 && j == m-1){
            return safe -1 ;
        }
        for(int d = 0; d < 4; d++){
            int r = i + nei[d], c = j + nei[d+1];
            if(r >= 0 && r < n && c >= 0 && c < m && grid[r][c] != -1){
                pq.push({r,c,grid[r][c]});
                grid[r][c] = -1;
            }
        }
    }
    return safe;
}