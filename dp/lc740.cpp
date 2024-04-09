#include <vector>
#include <iostream>

using namespace std;

/*
    Given an array of num [1,1,1,2,4,5,5,5,6]
    
    delete will get nums[i] points but also 
    remove all nums that satisfy nums[i] +/- 1 

    [1,2,3,3,7,7,13,18,18]
    
    sort the array
    using dp table to store the max num if taken the current 
    element or skip the current element
    
*/
int deleteAndEarn(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = 10001;
    vector<int> dp(n, 0); 
    for(auto i : nums){
        dp[i] += i;
    }
    int take = 0, skip = 0;
    for(int i = 0; i < n; i ++){
        int takeCurr = skip + dp[i];
        int skipCurr = max(skip, take);
        take = takeCurr; 
        skip = skipCurr;
    }
    return max(take, skip);
}

int main(){
    vector<int> nums{1,1,1,2,4,5,5,5,6};
    cout<<deleteAndEarn(nums);
}