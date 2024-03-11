#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
    Go through the words and count the words
*/
vector<string> topKFrequent(vector<string>& words, int k) {
    int n = words.size();
    unordered_map<string, int> m;
    for(int i = 0; i < n;i++){
        if(m.find(words[i]) == m.end()){
            m[words[i]] = 0;
        }
        m[words[i]] ++;
    }
    vector<vector<string>> s(n, vector<string>());
    for(auto p: m){
        s[p.second].push_back(p.first);
    }
    vector<string> res;
    for(int i = n-1; i >= 0; i--){
        if(s[i].size() == 0)
            continue;
        sort(s[i].begin(), s[i].end());
        for(auto str: s[i]){
            if(res.size() == k){
                return res;
            }
            res.push_back(str);
        }
    }
    return res;
}

int main(){
    vector<string> words {"the","day","is","sunny","the","the","the","sunny","is","is"};
    int k = 4;
    vector<string> res = topKFrequent(words, k);
    for(auto s: res){
        cout<<s<<" ";
    }
}