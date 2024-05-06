#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class TimeMap {
    using psi = pair<string, int>;
    unordered_map<string, vector<psi>> dir;
    unordered_map<string,int> mins; //min timestamp of each key
    unordered_map<string,int> maxs; //max timestamp of each key
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        if(dir.find(key) == dir.end()){
            dir[key] = {};
            mins[key] = timestamp;
        }
        maxs[key] = timestamp;
        dir[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(mins.find(key) == mins.end() || timestamp < mins[key]){
            return "";
        }
        //if the timestamp is greater than the max
        if(maxs[key] < timestamp){
            return dir[key].back().first;
        }
        //using binary search to find pair in dir[key] with the timestamp that is <= timestamp 
        int l = 0, r = dir[key].size()-1;
        auto pairs = dir[key];
        while( l <= r){
            int m = (r + l)/2;
            if(pairs[m].second == timestamp){
                return pairs[m].first;
            }
            else if(pairs[m].second < timestamp){
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        return pairs[r].first;
    }
};