#include <vector>

using std::vector;

/*
    Given an array of sorted integers nums, and a target n. Using the int in nums
    to make subsets that sums up to i from [1, n]. If sum subsets to form i is not
    possible, patch the array by adding nums, return the min patches so that nums
    can form all i from [1, n].

    the base case for this problem is 1 and 2, we have to add both of them if they 
    are not in the original array. The max sum we can make from any array is
    the sum of all nums. So starting from pSum = 1, we increment the pSum by itself
    if the next num in the array is greater than possible sum, else we increment by 
    the next num

*/
int minPatches(vector<int>& nums, int n) {
    long long pSum = 1, i = 0, res = 0;
    while(pSum <= n){
        if(i < nums.size() && nums[i] <= pSum){
            pSum += nums[i];
        }else{
            pSum += pSum;
            res++;
        }
    }
    return res;
}