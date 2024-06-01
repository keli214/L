#include <vector>
#include <iostream>
#include <queue>

using namespace std;

using pii = pair<int,int>;
int nei[5] = {-1, 0, 1, 0, -1};

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int n = maze.size(), m = maze[0].size(), step = -1;
    queue<pii> q; //using a queue for BFS
    q.push({entrance[0], entrance[1]}); //push the entrance to the queue
    maze[entrance[0]][entrance[1]] = '*'; //mark entrance as visited
    while(!q.empty()){ 
        int num = q.size(); //get the num of cells are this level
        ++step; 
        for(int i = 0; i < num; ++i){ //iterate through all of them
            auto [r, c] = q.front(); 
            q.pop();
            //check if a non entrance cell is on the border
            if((r != entrance[0] || c != entrance[1]) && (r == 0 || r == n -1 || c == 0 || c == m-1)){
                return step;
            }
            //check all the nei of current cell
            for(int d = 0; d < 4; ++d){
                int x = r + nei[d], y = c + nei[d+1];
                if(x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == '.'){
                    q.push({x,y});
                    maze[x][y] = '*'; //mark it as visited
                }
            }
        }
    }
    return -1;
}

int main(){
    vector<vector<char>> maze{{'+','+','+'},{'.','.','.'},{'+','+','+'}};
    vector<int> entrance{1,0};
    cout<<nearestExit(maze, entrance);
    
}