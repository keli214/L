#include <vector>
#include <iostream>

using namespace std;
/*
    [10,5,2,6] k = 100
    [10]->1 
    [10, 5] -> 1 + 2
    [5, 2] -> 1 + 2 + 2
  l 
*/
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int l = 0, r = 0, prod = 1, counts = 0;
    while(r < nums.size()){
        prod *= nums[r];
        while(prod >= k && l <= r){
            prod /= nums[l];
            l ++;
        }
        counts += r-l + 1;
        cout<<r<<" "<<l<<" "<<counts<<endl;
        r++;
    }
    return counts;
}

int main(){
    vector<int> nums{10,5,2,6};
    int k = 100;
    cout<<numSubarrayProductLessThanK(nums, k);
}