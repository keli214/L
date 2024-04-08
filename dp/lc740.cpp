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
    element
    
*/
int deleteAndEarn(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    vector<int> dp(n+1, 0); 
    for(int i = 0; i < n; i ++){
        if(i == 0 || nums[i-1] == nums[i]){
            dp[i+1] = dp[i] + nums[i];
        }
        else{
            int j = i-1;
            if(nums[j] + 1 == nums[i]){
                while(j >= 0 && nums[j] + 1 == nums[i]){
                    j--;
                }
            }
            int m = dp[j+1];
            for(int k = 0; k <= j; k++){
                m = max(m, dp[k]);
            }
            dp[i+1] = m + nums[i];
        }
    }
    int res = dp[n];
    for(auto i: dp){
        res = max(res, i);
    }
    return res;
}

int main(){
    vector<int> nums{1,1,1,2,4,5,5,5,6};
    cout<<deleteAndEarn(nums);
}