#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int maximumUniqueSubarray(vector<int>& nums) {
    //using a hashmap to store the loc of the last occurrance of num n
    //update n once we encounter a n that exists in m already
    //reduce start index l if l <= m[n]
    unordered_map<int,int> m;
    int l = 0, r = 0, res = 0, curr = 0;
    while(r < nums.size()){
        if(m.find(nums[r]) != m.end()){
            while(l <= m[nums[r]]){
                curr -= nums[l];
                l ++;
            }
        }    
        m[nums[r]] = r;    
        curr += nums[r];
        res = res < curr ? curr : res;
        r++;
    }
    return res;
}

int main(){
    vector<int> nums {4,2,4,5,6};
    cout<<maximumUniqueSubarray(nums);
}