#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
/*
    maximize the number of partitions in string s such that each subarray contains unqiue characters to that subarray
    for each char s[i] in s, find the last time it occurs in s s[l]
        for any char s[j] included from s[i] to s[l], we also check the last occurance of s[j]
            if that's larger, we update the s[l]
    start from s[l] + 1
*/
vector<int> partitionLabels(string s) {
    vector<int> res;
    size_t r = 0, n = s.size();
    while(r < n){
        //find the last 
        unordered_set<char> test;
        test.insert(s[r]);
        size_t last = s.find_last_of(s[r]), curr = r + 1;
        while(last != string::npos && curr < last){
            if(test.find(s[curr]) == test.end()){
                last = max(last, s.find_last_of(s[curr]));
                test.insert(s[curr]);
            }
            curr ++;
        }
        res.push_back(last-r+1);
        r = last + 1;
    }
    return res;
}

int main(){
    string s = "ababcbacadefegdehijhklij";
    vector<int>res = partitionLabels(s);
    for(auto l: res){
        cout<<l;
    }
}