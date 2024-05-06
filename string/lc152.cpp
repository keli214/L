#include <vector>
#include <iostream>

using namespace std;

/*
    Using the fact the max product must exist in the prefix product or suffix product 
    reset the product when encounter 0
*/
int maxProduct(vector<int>& nums) {
    if(nums.size() < 0) return 0;
    int prefix = 1, res = nums[0], suffix = 1;
    for(int i = 0; i < nums.size(); i++){
        prefix = prefix == 0 ? nums[i] : prefix * nums[i];
        suffix = suffix == 0 ? nums[nums.size()-i-1] : suffix * nums[nums.size()-i-1];
        res = max(res, max(prefix, suffix));
    }
    return res;
}

int main(){
    vector<int> nums{2,-5,-2,-4,3};
    cout<<maxProduct(nums);
}