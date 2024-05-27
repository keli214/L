#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
    find all the nonempty subsets such that they don't contain 
    any pair of nums that the abs difference between the two is K

    DP:
    sort the nums, then use back tracking to find all the subsets
    while finding the subsets, checking the difference between curr with  
    the acceptable range 

    Arrangement:
    range the nums by their module by k and store the freq of each element
    for each group with the same module
    we find the number of subsets within the group
    we sort the nums first
    for each number within a group
    we sort the nums first then check if we can add it into the subset that contains prev num
    if so, update the num of subset to (prevTake + prevNotTaken) * curr_possible_subsets
    else the num of subset becomes (prevNotTaken) * curr_possible_subsets
    the total number of subsets from all group is the product 
*/

// DP solution
// int res = 0;
// void backtrack(vector<int>& nums, int k, int n, unordered_map<int,int>& tests){
//     if(n == nums.size()){    
//         res++;
//         return;
//     }
    
//     if(!tests[nums[n]-k]){
//         tests[nums[n]]++;
//         backtrack(nums, k, n+1, tests);
//         tests[nums[n]]--;
//     }
//     backtrack(nums, k, n+1, tests);
// }

// int beautifulSubsets(vector<int>& nums, int k) {
//     sort(nums.begin(), nums.end());
//     unordered_map<int,int> tests;
//     backtrack(nums, k, 0, tests);
//     return res-1;
// }

int beautifulSubsets(vector<int>& nums, int k) {
    unordered_map<int, vector<int>> resid;
    for(auto n : nums){
        resid[n%k].push_back(n);
    }
    int res = 1;
    for(auto &[resid, group]: resid){
        sort(group.begin(), group.end());
        unordered_map<int,int> freq;
        for(auto &n: group){
            freq[n] ++;
        }
        int prevEle = INT_MIN, prevTake = 0, prevNotTake = 1, take = 0, notTake = 0;
        for(auto& n: group){
            int f = freq[n];
            int numSets = pow(2, f)-1;
            if(prevEle + k == n){
                take = prevNotTake * numSets;
                notTake = prevTake + prevNotTake;
            }else{
                take = (prevTake + prevNotTake) * numSets;
                notTake = prevTake + prevNotTake;
            }
            prevEle = n;
            prevTake = take;
            prevNotTake = notTake;
            cout<<prevTake<<" "<<prevNotTake<<endl;
        }
        res *= (take + notTake);
    }
    return res - 1 ;
}

int main(){
    vector<int> nums{2,4,6};
    cout<<beautifulSubsets(nums, 2);
}