#include <vector>
#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;
/*
    Calculate the dist between all pair of vertices
    We find the shortest len from the first vertices in the graph 
    to all other vertices
    O(E + VlogV)
*/

using ii = pair<int,int>;

static bool compare(ii a, ii b){
    return a.second > b.second;
}

int minCostConnectPoints(vector<vector<int>>& points) {
    vector<bool> visited(points.size(), false);
    vector<int> dist(points.size(), INT_MAX);
    
    priority_queue<ii, vector<ii>, function<bool(ii, ii)>> pq(compare);
    int len = 0;
    //push the first point
    dist[0] = 0;
    pq.push({0, 0});
    int visitedNode = 1;
    while(visitedNode <= points.size()){
        int curr = pq.top().first;
        if(visited[curr]){
            pq.pop();
            continue;
        }
        cout<<curr<<" "<<pq.top().second<<endl;
        len += pq.top().second;
        pq.pop();
        visited[curr] = true;
        visitedNode ++;
        //for all of the unvisited node, check the distance
        for(int i = 0; i < points.size(); i++){
            if(i != curr && !visited[i]){
                int d = abs(points[curr][0] - points[i][0]) 
                        + abs(points[curr][1] - points[i][1]);
                if(dist[i] > d){
                    pq.push({i, d});
                }
            }
        }
    }
    return len; 
}

int main(){
    vector<vector<int>> points {{3,12},{-2,5},{-4,1}};
    cout<<minCostConnectPoints(points);
}