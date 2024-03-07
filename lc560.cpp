#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

/*
    Store the prefix sum and their count in the hashmap
    using the difference between to check if there is a 
    subarray (k-i) sums to k
    
*/

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> m {{0,1}}; 
    int curr = 0, res = 0;
    for(int i = 0; i < nums.size(); i ++){
        curr += nums[i]; 
        if(m.find(curr-k) != m.end()){
            res += m[curr-k];
        }
        if(m.find(curr) == m.end()){
            m[curr] = 0;
        }
        m[curr] += 1;
    }
    return res;
}

int main(){
    vector<int> nums {1,-1,0};
    int k = 0;
    cout<<subarraySum(nums, k);
}