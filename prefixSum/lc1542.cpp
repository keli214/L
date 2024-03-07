#include <string>
#include <iostream>
#include <unordered_map>
#include <bitset>
using namespace std;
/*
    "3242415"
    find the longest substring with even num of digits and at most 1 odd digit
    000100,00000
    get the even/odd of current substring (0-i) 
    
*/
int longestAwesome(string s) {
    int cur = 0, res = 0;
    vector<int> m(1<<10, -2);
    m[0] = -1;
    cout<<m.size();
    for(int i = 0; i < s.size(); i++){
        cur ^= 1 << (s[i]-'0');
        for(int j = 0; j < 10; j++){
            int temp = cur ^ (1 << j);
            if(m[temp] != -2){
                res = max(res, i-m[temp]);
            }
        }
        if(m[cur] != -2){
            res = max(res, i-m[cur]);
        }
        else{
            m[cur] = i;
        }
    }
    return res;
}

int main(){
    string s = "3242415";
    cout<<longestAwesome(s);
}