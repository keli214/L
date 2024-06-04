#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int longestPalindrome(string s) {
    unordered_map <char, int> m;
    for(auto &c: s){
        m[c]++;
    }
    int res = 0, middle = 0;
    for(auto &[k,v]: m){
        if(v >= 2)
            res += v/2;
        if(!middle) middle = v%2;
    }
    return res*2 + middle;
}

int main(){
    string s = "abccccdd";
    cout<<longestPalindrome(s);
}