#include <iostream>
#include <string>

using namespace std;

/*
    Given a string s and a string t and an integer maxCost 
    changing from s[i] to t[i] costs | s[i] - t[i] |
    find the maxlength of substring such that the cost of changing the 
    entire substring is not greater than maxCost

    we can solve this with a two pointer method 
    keep incrementing the right ptr while the cost <= maxCost
    incrementing the left ptr while the cost > maxCost
    return the max(r-l+1)

    prefix sum: cal the cost of each char in s
    find the prefix sum of the cost 
    


*/

int equalSubstring(string s, string t, int maxCost) {
    int l = 0, r = 0, res = 0, cost = 0;
    while(r < s.size()){
        cost += abs(s[r] - t[r]);
        while(l <= r && cost > maxCost){
            cost -= abs(s[l] - t[l]);
            l++;
        }
        res = max(res,r-l + 1);
        r++;
    } 
    return res;
}

int main(){
    string s {"abcd"}, t {"bcdf"};
    cout<<equalSubstring(s, t, 3);
    
}