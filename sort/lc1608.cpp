#include <vector>

using namespace std;
/*
    check if there exists n nums that's larger than n 
    (nums.size() - n) < n 
    find the smallest nums in n and check the size of nums
    using vector of length n + 2 to keep the count of digit 1-n 
    

*/
// int specialArray(vector<int>& nums) {
//     sort(nums.begin(), nums.end());
//     int n = nums.size();
//     for(int i = 0; i < nums.size(); i++){
//         if((i == 0 && nums[n-1-i] < i) || (i > 0 && nums[n-1-i] < i && nums[n-i] >= i)){
//             return i;
//         }
//     }
//     if(nums[0] >= n){
//         return n;
//     }
//     return -1;
    
// }

int specialArray(vector<int>& nums) {
    int n = nums.size();
        vector<int> counts(n+2, 0);
        for(auto &i: nums){
            if(i > n)
                counts[n+1]++;
            else if(i < 0)
                counts[0]++;
            else
                counts[i+1]++;
        }
        if(counts[0] == n){
            return 0;
        }
        for(int i = 0; i <= n; i++){
            counts[i] += counts[i-1];
            if(n - counts[i] == i){
                return i;
            }
        }
        return -1;
}

int main(){

}