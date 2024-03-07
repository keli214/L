#include <deque>
#include <iostream>
#include <vector>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    /*
        for element r we are removing, if r equals to top of dq, pop the front of the dq;
        for curr element c we are inserting, if c is larger than the back of the dq, 
        we pop the back of the dq until all element in dq is less than c; 
    */
    deque<int> dp;
    vector<int> res;
    for(int i = 0; i < nums.size(); i++){
        //remove i - k
        if(i-k >= 0 && !dp.empty() && nums[i-k] == dp.front()){
            dp.pop_front();
        }   
        while(!dp.empty() && dp.back() < nums[i]){
            dp.pop_back();
        }
        dp.push_back(nums[i]);   
        for(auto i: dp){
            cout<<i<<" ";
        }  
        cout<<"\n";
        if(i >= k -1)
            res.push_back(dp.front());
    }   
    return res; 
}

int main (){
    vector<int> nums {1,3,1,2,0,5};
    int k = 3;
    vector<int> res = maxSlidingWindow(nums, k);
    for(auto i: res){
        cout<<i<<" ";
    }

}