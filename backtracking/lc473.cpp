#include <vector>
#include <iostream>
#include <numeric>

using namespace std;
//seperating the matchsticks into 4 vectors, check if the sum of each vector is equal
bool helper(vector<int>& matchsticks, vector<int>& square, int target, int idx){
    
    if(idx == matchsticks.size())
        return true;
    
    for(int i = 0; i < 4; i ++){
        if(square[i] + matchsticks[idx] > target) 
            continue;
        int j = i-1;
        while(j >= 0){
            if(square[i] == square[j])
                break;
            j--;
        }
        if(j != -1)
            continue;
        square[i] += matchsticks[idx];
        if(helper(matchsticks, square, target, idx + 1))
            return true;
        square[i] -= matchsticks[idx];
    }
    return false;
}


bool makesquare(vector<int>& matchsticks) {
    //get the sum of the matchsticks
    int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if(sum % 4 != 0 || matchsticks.size() < 4) return false;
    sort(matchsticks.begin(), matchsticks.end());
    vector<int> square(4, 0);
    return helper(matchsticks, square, sum/4, 0);
}

int main(){
    vector<int> matchsticks{1,1,2,2,2};
    cout<<makesquare(matchsticks);
}
