#include <vector>
#include <iostream>

using namespace std;

int findDuplicate(vector<int>& nums) {
    int fast = nums[nums[0]], slow = nums[0]; //0, 0
    while(fast != slow){ 
        fast = nums[nums[fast]]; 
        slow = nums[slow];
    }
    slow = 0;
    while(nums[fast] != nums[slow]){
        fast = nums[fast];
        slow = nums[slow];
    }
    return fast;
}

int main(){
    vector<int> nums{3,1,3,4,2};
    cout<<findDuplicate(nums);
    return 0;
}