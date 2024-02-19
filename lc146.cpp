#include <list>
#include <unordered_map>
using namespace std;

/*
    LRUCache(int capacity) 
        Initialize the LRU cache with positive size capacity.
    int get(int key) 
        Return the value of the key if the key exists, otherwise return -1.
    void put(int key, int value) 
        Update the value of the key if the key exists. 
        Otherwise, add the key-value pair to the cache. 
        If the number of keys exceeds the capacity from this operation, 
        evict the least recently used key.
*/
class LRUCache{
    int capacity;
    unordered_map<int, list<pair<int,int>>::iterator > m; //key: input key, val: iterator to a given input 
    list<pair<int,int>> cache; //beg: most recent, end: least recent

    LRUCache(): capacity(0) {}

    LRUCache(int _capacity) {
        capacity = _capacity;
    }
    
    int get(int key) {
        //key doesn't exist
        if(m.find(key) == m.end())
            return -1;
        //remove element pointed by the iterator from the list 
        //and add it to the begin
        auto pairPtr = m[key];
        cache.splice(cache.begin(), cache, pairPtr);
        return cache.front().second;
    }
    
    void put(int key, int value) {
        //if key exists
        if(m.find(key) != m.end()){
            auto pairPtr = m[key];
            pairPtr->second = value;
            cache.splice(cache.begin(), cache, pairPtr);
        }
        else{
            cache.emplace_front(key,value);
            m[key] = cache.begin();
            if(cache.size() > capacity){
                auto pairPtr = cache.back();
                m.erase(pairPtr.first);
                cache.pop_back();
            }
        }
    }
};
