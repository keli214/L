#include <vector>
#include <iostream>
#include <queue>
#include <functional>

using namespace std;

/*
    You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed).
    You can move up, down, left, or right, and you wish to find a route that requires the minimum effort
    A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
    Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

    using dijkstra algorithm to find a shortest path from top left to all other cells in heights
    the distance function will return the effort of the path

*/
int nei[5] =  {-1,0,1,0,-1};

using pii = pair<pair<int,int>, int>;

int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size(), m = heights[0].size();
    //using a priority queue to store the idx and min maxEffort of encounter cells so far
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    //using a 2D array to store the dist for updating the distance
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[0][0] = 0;
    pq.push({{0,0}, 0});

    while(!pq.empty()){
        pii curr = pq.top();
        int i = curr.first.first, j = curr.first.second, tmp = heights[i][j], e = curr.second;
        //if the i and j is the bottom, return the d
        if(i == n-1 && j == m-1)
            return e;
        //mark it as visited
        
        pq.pop();
        //for each neighbor
        for(int d = 0; d < 4; d++){
            int r = i + nei[d], c = j + nei[d+1];
            if(r >= 0 && r < n && c >= 0 && c < m ){
                //update the effort if the effort is smaller
                int currE = max(e, abs(tmp - heights[r][c]));
                if(dist[r][c] > currE){
                    dist[r][c] = currE;
                    pq.push({{r,c}, currE});
                }
            }
        }
        for(auto r: dist){
            for(auto i: r){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}


int main(){
    vector<vector<int>> heights {{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};
    cout<<minimumEffortPath(heights);
}