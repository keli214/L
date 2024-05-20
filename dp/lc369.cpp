#include <iostream>
#include <vector>
using namespace std;

int total = 0;
void backtrack(vector<int>& nums, vector<int> selected, int n){
    int curr = 0;
    for(int i = 0; i < nums.size(); i++){
        if(selected[i]){
            curr ^= nums[i];
        }
    }
    total += curr;
    for(int i = n; i < nums.size(); i++){
        selected[i] = 1;
        backtrack(nums, selected, i + 1);
        selected[i] = 0;
    }
}

int subsetXORSum(vector<int>& nums) {
    vector<int> selected(nums.size(), 0);
    backtrack(nums, selected, 0);
    return total;
}

int main(){
    vector<int> nums{3,4,5,6,7,8};
    cout<<subsetXORSum(nums);
}