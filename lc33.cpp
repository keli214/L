#include <iostream>
#include <vector>

using namespace std;
/*   
     l     m       r
    [4,5,6,7,8,1,2,3], t = 8
*/
int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size();
    while(l <= r){
        int m = l + (r-l)/2;
        if(nums[m] == target)
            return m;
        /*If the middle is larger than the target, we first check if we need to go the right
          by checking if the smallest element in the left side is greater than target and the 
          middle number is larger than the right */
        if(nums[m] > target){
            if(nums[l] > target && nums[m] > nums[r])
                l = m+1;
            else
                r = m-1;
        }    
        else{//nums[m] < target
            if(nums[r] < target && nums[m] < nums[l])
                r = m-1;
            else
                l = m+1;
        }
    }
    return -1;
}

int main(){
    vector<int> nums{4,5,6,7,8,1,2,3};
    int t = 8;
    cout<<search(nums, t);
}