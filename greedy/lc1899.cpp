#include <vector>
#include <iostream>

using namespace std;

/*
    find n triples such that max(triples[i]_1,...,triples[i]_n) = target[i]
    find all triples such that t[i] = target[i] and all other num is less than target
    if all 3 num in target can be find in that set
    return true
*/
bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    int exist[3] {};
    for(int i = 0; i < triplets.size(); i++){
        int curr[3] {};
        bool test = true;
        for(int j = 0; j < 3; j++){
            if(triplets[i][j] > target[j]){
                test = false;
            }
            else if(triplets[i][j] == target[j]){
                curr[j] = 1;
            }
        }
        if(test){
            for(int j = 0; j < 3; j++){
                exist[j] |= curr[j];
            }
        }
    }
    for(int i = 0; i < 3; i++){
        if(!exist[i])
            return false;
    }
    return true;
}

int main(){
    vector<vector<int>> triples{{3,4,5},{4,5,6}};
    vector<int> target {5,5,5};
    cout<<mergeTriplets(triples, target);
}