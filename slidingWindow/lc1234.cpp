#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int balancedString(string s) {
    unordered_map<char,int> counts, test, substr;
    for(int i = 0; i < s.size(); ++i){
        counts[s[i]]++;
    }    
    int n = s.size(), t = n/4, res = n;
    int l = 0, r = 0;
    while(r < n){
        counts[s[r]]--;
        while(l <= n && counts['Q'] <= t && counts['W'] <= t && counts['E'] <= t && counts['R'] <= t){
            res = min(res, r-l+1);
            counts[s[l++]]++;
        }
        r++;
    }
    return res;
}