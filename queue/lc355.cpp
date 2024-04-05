#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Twitter {
    //storing the users and their most recent 10 posts in two dictionaries
private:
    using pii = pair<int,int>;
    vector<int> users;
    unordered_map<int, vector<pii>> posts; //key: user_id, val: most recent 10 posts with their time stamp
    unordered_map<int, unordered_set<int>> followees; //key: user_id, val: followees
    int timeStamps;
public:
    Twitter() {
        timeStamps = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        if(posts[userId].size() == 10){
            posts[userId].erase(posts[userId].begin());        
        }
        posts[userId].push_back({timeStamps++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        //using a maxHeap to find the most recent 10 posts of the user and its followees
        priority_queue<pii> feeds;
        for(auto p: posts[userId]){
            feeds.push(p);
        }
        for(auto f: followees[userId]){
            for(auto p: posts[f]){
                feeds.push(p);
            }
        }
        vector<int> res;
        for(int i = 0; i < 10 && !feeds.empty(); i++){
            res.push_back(feeds.top().second);
            feeds.pop();
        }  
        return res; 
    }
    
    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};