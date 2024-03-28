#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LFUCache {
        /*
            Storing the (val, freq) pair in a linked list
            Using a hashmap to store the inserted node with their position in the list
            Using another hashmap to store all linked list with the same freq together

        */
    private:
        using pii = pair<int,int>;
        unordered_map<int, pii> m; //nodes
        unordered_map<int, list<int>::iterator> nodes; //key: key, val: list pos
        unordered_map<int, list<int>> freqs;//key: freq, val: list of key
        int minFreq;
        int cap;
        int size;

    public:
        /*
            Initializes the object with the capacity of the data structure.
        */
        LFUCache(int capacity) {
            cap = capacity;
            size = 0;
        }
        /*
            Gets the value of the key if the key exists in the cache. 
            Otherwise, returns -1.
            O(1)
        */
        int get(int key) {
            //check if the key is in the LFU cache
            if(m.find(key) != m.end()){
                //get the val and freq of the key
                int val = m[key].first, freq = m[key].second;
                //remove node from freqs[freq]
                auto node = nodes[key];
                freqs[freq].erase(node);
                //update min freq is freq is minFreq
                if(freq==minFreq && freqs[freq].empty()){
                    minFreq++;
                }
                //initialize list
                if(freqs.find(freq+1) == freqs.end()){
                    freqs[freq+1] = {};
                }
                //insert key to the begining of (freq + 1) list
                freqs[freq+1].push_front(key);
                //update the nodes & m map
                nodes[key] = freqs[freq+1].begin();
                m[key] = {val, freq+1};
                return val;
            }
            return -1;
        }
        /*
            Update the value of the key if present, or inserts the key if not already present. 
            When the cache reaches its capacity, 
            it should invalidate and remove the least frequently used key before inserting a new item. 
            For this problem, when there is a tie (i.e., two or more keys with the same frequency), 
            the least recently used key would be invalidated.
            O(1)
        */
        void put(int key, int value) {
            //if key exists in the cache
            if(nodes.find(key) != nodes.end()){
                //get the node
                auto node = nodes[key];
                int freq = m[key].second;
                //remove node from freqs[freq]
                freqs[freq].erase(node);
                //if the freq is minFreq and the list becomes empty 
                if(freq == minFreq && freqs[freq].empty()){
                    minFreq ++;
                }
                //insert node to the begining of (freq + 1) list
                if(freqs.find(freq+1) == freqs.end()){
                    freqs[freq+1] = {};
                }
                freqs[freq+1].push_front(key);
                //update the nodes map
                nodes[key] = freqs[freq+1].begin();
                m[key] = {value, freq+1};
            }
            else{//if key doesn't exists in the cache
                //check the cache is full
                if(size == cap){
                    //remove LFU node
                    int LFU_key = freqs[minFreq].back();
                    nodes.erase(LFU_key);
                    m.erase(LFU_key);
                    freqs[minFreq].pop_back();
                    //reduce size
                    size --;
                }
                //add new node
                minFreq = 1;
                m[key] = {value, minFreq};
                freqs[minFreq].push_front(key);
                nodes[key] = freqs[minFreq].begin();
                //inc size
                size ++;
            }

        }
};

