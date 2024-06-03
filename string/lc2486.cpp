#include <string>
#include <iostream>
using namespace std;

/*
    find how many chara u need to append to s such that t is a 
    subsequent of s

    looping through s chara by chara with a sliding window
    increase the right point if curr char is a match in t    
*/
int appendCharacters(string s, string t) {
    int j = 0;
    for(int i = 0; i < s.size(); ++i){
        if(t[j]==s[i]){
            ++j;
        }    
    }
    return t.size()-j;
}

int main(){
    string s = "coachding", t = "coding";
    cout<<appendCharacters(s,t);
}