#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

/*
    "abciiidef", k = 3
     ----
    Using a sliding window to find the max num of vowels within a window
*/
int maxVowels(string s, int k){
    unordered_set<char> vowels{'a','e','i','o','u'};
    int l = 0, r = 0, res = 0, curr = 0;
    while(r < s.size()){
        if(r - l == k){
            if(vowels.find(s[l]) != vowels.end()){
                curr --;
            }
            l++;
        }
        if(vowels.find(s[r]) != vowels.end()){
            curr++;
        }
        r++;
        res = max(res, curr);
    }
    return res;
}

int main(){
    string s = "weallloveyou";
    cout<<maxVowels(s, 7);
}