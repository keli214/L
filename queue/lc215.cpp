#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> qp;
    for(int i = 0; i < nums.size(); i++){
        qp.push(-nums[i]);
        if(qp.size() > k){
            qp.pop();
        }
    }
    return -qp.top();
}

int main(){
    vector<int> nums{3,2,1,5,6,4};
    cout<<findKthLargest(nums, 2);
}

