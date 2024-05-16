#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*  Given an array of nums, return the rank of each num 
    from highest to lowest
    BF: nlogn, sort then find the rank
*/

vector<string> findRelativeRanks(vector<int>& score) {
    vector<int> sorted(score);
    sort(sorted.begin(), sorted.end(), greater<int>());
    vector<string> res(score.size());
    string top[3] = {"Gold Medal","Silver Medal","Bronze Medal"};
    unordered_map<int, string> ranks;
    for(int rank = 0; rank < sorted.size(); rank++){
        ranks[sorted[rank]] = rank < 3 ? top[rank]: to_string(rank+1);
    }
    for(int i = 0; i < score.size(); i++){
        res[i] = ranks[score[i]];
    }
    return res;

}

int main(){
    vector<int> score{5,4,3,2,1};
    vector<string> res = findRelativeRanks(score);
    for(auto s: res){
        cout<<s<<" ";
    }
}