#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

string RabinKarp(string& s, int n){
    unordered_map<long, vector<int>> m;
    int b = 256, p = INT_MAX;
    long t = 0, h = 1;
    //calculate b^(n-1) % p
    for(int i = 0; i < n-1; i++){
        h = (h*b) % p;
    }
    //calculate the hash value of the first substring of length n 
    for(int i = 0; i < n ; i++){
        t = (t * b + s[i]) % p;
    }
    m[t].push_back(0);
    for(int i = 0; i < s.size()-n; i++){
        t = (b * (t - s[i] * h) + s[i+n])%p;
        if (t < 0)
            t = (t + p);
        for(auto idx : m[t]){
            if(s.substr(idx, n) == s.substr(i+1, n)){
                return s.substr(idx, n);
            }
        }
        m[t].push_back(i+1);
    }
    return "";
}

string longestDupSubstring(string s) {
    /* given a string of length n
     the longest possible substring will have the length n-1
     aaaa - > aaa
     We can use binary search to find the max length duplicated substring
     l = 1,  h = n-1
     how to see if there is a duplicated substring of length x

     ex : 
        banana
        n = 6, h = 5
        first check if there is a substring of size m = 2, 4
        if yes, 
            l = m + 1 = 3
        if no, 
            r = m - 1 = 3
    */
    string res = "";
    int n = s.size(), l = 1, h = n-1;
    while(l <= h){
        int m = l + (h-l)/2;
        cout<<m<<endl;
        string tmp = RabinKarp(s, m);
        res = tmp.size() > res.size() ? tmp : res;
        if(tmp != "")
            l = m + 1;
        else
            h = m-1;
    }
    return res;
}

int main(){
    string s = "bannna";
    cout<<longestDupSubstring(s);
    return 0;
}