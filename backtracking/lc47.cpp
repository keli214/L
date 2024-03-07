#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& curr, vector<int> visited){
    if(curr.size() == nums.size()){
        res.push_back(curr);
        return;
    }
    for(int i = 0; i < nums.size(); i++){
        
        if(!visited[i]){
            if(i > 0 && nums[i] == nums[i-1] && !visited[i-1]){
                continue;
            }
            curr.push_back(nums[i]);
            visited[i] = 1;
            helper(nums, res, curr, visited);
            curr.pop_back();
            visited[i] = 0;
        }
        
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> curr, visited(nums.size(), 0);
    sort(nums.begin(), nums.end());
    helper(nums, res, curr, visited);
    return res;
}

int main(){
    vector<int> nums {1,2,1};
    vector<vector<int>> res = permuteUnique(nums);
    for(auto v: res){
        for(auto i: v){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}