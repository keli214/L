#include <vector>
#include <iostream>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size(), test = 0;
    for(int i = 1; i<= n; i++){
        test ^= i;
    }
    for(auto i: nums){
        test ^= i;
    }
    return test;
}

int main(){
    vector<int> nums {0,2,3};
    cout<<missingNumber(nums);
    return 0;
}

