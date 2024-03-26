#include <vector>
#include <iostream>

using namespace std;

/*
             /           /|
            /           / |
         __/   ----> __/  |     
       _/                 |   _/
    __/                   |__/
                    left    right
*/      
bool search(vector<int>& nums, int target) {
    int l = 0, h = nums.size()-1, m = 0;
    while(l <= h){
        m = (l+h)/2;
        cout<<m<<' '<<l<<' '<<h<<endl;
        if(nums[m] == target){
            return true;
        }
        /*
            If nums[m] == nums[h] == nums[l], we reduce the size of the window 
        */
        if(nums[m] == nums[h] && nums[m] == nums[l]){
            l++;
            h--;
        }
        /*
            if num at m is less than target and m is in right side 
            of the rotated array, check the right most element is larger than target
            if it is not then we only need to check the left side of the array
        */
        else if(nums[m] < target){
            if(nums[m] < nums[l] && nums[h] < target){
                h = m-1;
            }
            else{
                l = m+1;
            }
        }
        else{//m > target
            //If m in the left side of the rotated array, check the 
            if(nums[m] > nums[h] && nums[l] > target){
                l = m + 1;
            }
            else{
                h = m - 1;
            }
        }
    }
    return false;
}

int main(){
    vector<int> nums {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
    int t = 2;
    cout<<search(nums, t);
}