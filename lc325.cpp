#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

int maxSubArrayLen(vector<int> nums, int target) {
    unordered_map<int, int> m {{0,-1}}; //key: sum, val: idx
    int curr = 0, res = 0;
    for(int i = 0; i < nums.size(); i ++){
        curr += nums[i]; 
        if(m.find(curr-target) != m.end()){
            res = max(res, i-m[curr-target]);
        }
        if(m.find(curr) == m.end()){
            m[curr] = i;
        }
    }
    
    return res;
}
int main(){
    vector<int> nums {1,2,1,2,1};
    cout<< maxSubArrayLen(nums, 3);
}
