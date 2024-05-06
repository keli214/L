#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;



/*
    For a point (x,y), we first search for points that has the same x-coordinates
    for each of the point (x, y_), we calculate the width of the potential square: w = abs(y - y_)
    then we check if there are two points (x+w, y), (x+w, y_)

*/
class DetectSquares {
private:
    struct pair_hash {
        inline std::size_t operator()(const std::pair<int,int> & v) const {
            return v.first*31+v.second;
        }
    };
    unordered_map<pair<int, int>, int, pair_hash> points;
    unordered_map<int, vector<int>> xMap;

public:
    DetectSquares() {
    }
    
    void add(vector<int> point) {
        pair<int,int> p = {point[0],point[1]};
        if(points.find(p) == points.end()){
            points[p] = 0;
        }
        points[p]++;
        if(xMap.find(point[0]) == xMap.end()){
            xMap[point[0]] = {};
        }
        xMap[point[0]].push_back(point[1]);
    }
    
    int count(vector<int> point) {
        int counts = 0, x = point[0], y = point[1];
        //search for the points 
        for(auto yP: xMap[x]){
            if(yP != y){
                //calculate width
                int w = abs(y - yP);
                if(points.find({x+w, y}) != points.end() && points.find({x+w, yP}) != points.end())
                    counts += points[{x+w, y}] * points[{x+w, yP}];
                if(points.find({x-w, y}) != points.end() && points.find({x-w, yP}) != points.end())
                    counts += points[{x-w, y}] * points[{x-w, yP}];
            }
            
        }
        return counts;
    }
};

int main(){
    DetectSquares d;
    d.add({419,351});
    d.add({798,351});
    d.add({798,730});
    cout<<d.count({419,730});
}