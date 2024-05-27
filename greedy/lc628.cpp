#include <vector>
#include <numeric>
#include <iostream>

using namespace std;
int maximumProduct(vector<int>& nums) {
    //if there are only three nums 
    if(nums.size() == 3){
        return accumulate(nums.begin(), nums.begin() + 3, 1, multiplies<int>());
    }
    //split the nums into negatives, positives, and zeros
    vector<int> pos, neg;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] < 0){
            neg.push_back(nums[i]);
        }
        else if(nums[i] > 0){
            pos.push_back(nums[i]);
        }
    }
    //sort the neg by magnitude
    sort(neg.begin(), neg.end(), less<int>());
    //if there are more than 2 negative nums
    int maxNeg = 0;
    if(neg.size() >= 2){
        //if all neg numbers
        if(pos.size() < 1){
            //there are zeros
            if(pos.size() + neg.size() != nums.size()) return 0;
            //return the least negative product
            return accumulate(neg.rbegin(), neg.rbegin() + 3, 1, multiplies<int>());
        }
        maxNeg = neg[0] * neg[1];
    }
    sort(pos.begin(), pos.end(), greater<int>());
    if(pos.size() < 3){
        return maxNeg * pos[0];
    }
    return max(maxNeg * pos[0],  pos[0] * pos[1] * pos[2]);
}