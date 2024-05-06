#include <vector>
#include <iostream>

using namespace std;
/*
    To shuffle the array without extra memory space in O(n) time 
    Let nums = [x1, ..., xN, y1, ..., yN]
    we store each pair of (xi, yi) pair in yi as one of the constriant is 
    nums[i] <= 10^3 which costs 10 bits in binary.
    Thus we can fit two num in one int(32bits) 
    We store the two number by shifting xi 10 bits the left then OR with yi 

*/
vector<int> shuffle(vector<int>& nums, int n) {
    for(int i = n ; i < nums.size(); ++i){
        nums[i] = (nums[i] << 10) | nums[i - n];
    }
    int i = 0;
    for(int j = n; j < nums.size(); ++j, i+=2){
        nums[i] = nums[j] & 1023;
        nums[i+1] = nums[j] >> 10;
    }
    return nums;
}