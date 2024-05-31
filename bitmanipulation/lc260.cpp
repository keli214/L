#include <vector>

std::vector<int> singleNumber(std::vector<int>& nums) {
    int t = nums[0];
    for(int i = 1; i < nums.size(); ++i){
        t ^= nums[i];
    }
    int i = 1;
    while(!(i&t)){
        i <<= 1;
    }
    int a = t, b = t;
    for(auto n: nums){
        if(n & i)
            a ^= n;
        else
            b ^= n; 
    }
    return {a, b};
}