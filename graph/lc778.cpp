#include <vector>
#include <iostream>
#include <queue>

using namespace std;
/*
    Using dijkstra to find a shortest path from start to finish
    the distance func set to the max val of path 
*/

int nei[5] {-1, 0, 1, 0, -1};
typedef pair<pair<int,int>, int> pii;
int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<vector<int>> dist(n,vector<int>(m, INT_MAX));
    
    //start cell
    pq.push({{0,0}, 0});
    dist[0][0] = 0;

    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        
        int i = curr.first.first, j = curr.first.second, t = curr.second;
        if(i == n-1 && j == m-1){
                return t;
            }
        for(int d = 0; d < 4; d++){
            int r = i + nei[d], c = j + nei[d+1];
            
            if(r >= 0 && r < n && c >= 0 && c < m){
                int time = max(grid[r][c], t);
                //update the time to r,c if the current path has a smaller time
                if(time < dist[r][c]){
                    dist[r][c] = time;
                    pq.push({{r,c}, time});
                }
            }
        }
        // for(auto r: dist){
        //     for(auto i: r){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
    }
    return -1;
}

int main(){
    vector<vector<int>> grid = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    cout<<swimInWater(grid);
}