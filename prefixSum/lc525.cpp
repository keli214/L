#include <vector>
#include <iostream>
using namespace std;
/*
    Keep the difference of the zero counts and one counts with the corresponding indicies
    in a hashmap to find substring that has equal num of 0s and 1s
    [0,1,0,0,1]
*/
int findMaxLength(vector<int>& nums) {
    vector<int> m(2*nums.size()+1, INT_MIN);
    int diff = 0, res = 0, n = nums.size();
    m[n] = -1;
    for(int i = 0; i < nums.size(); i++){
        diff += nums[i] == 0 ? -1 : 1;
        if(diff == 0)
            res = i+1;
        if(m[diff+n] >= -1)
            res = max(res, i-m[diff+n]);
        else
            m[diff+n] = i;
    }        
    return res;
}

int main(){
    vector<int> nums{0,1,0,0,1};
    cout<<findMaxLength(nums);
}