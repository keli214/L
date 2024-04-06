#include <string>
#include <iostream>
#include <vector>

using namespace std;

//Calculating the offset of each number using k and the number of permutation at each index 
// Since n will result in n! permutation
// let i be the number at index n-i
// i = k/(n-1)!
// if k % (n-1) == 0, i = i-1;
void helper(vector<int>& nums, const int* factorials, int k, string& ans){
    if(nums.size() == 1){
        ans += '0' + nums[0];
        return;
    }
    int nF = *(factorials + (nums.size()-1));
    int idx = k%nF == 0 ? k/nF - 1 : k/nF;
    k = k - idx*nF;
    ans += '0' + nums[idx];
    nums.erase(nums.begin() + idx);
    helper(nums,factorials, k, ans);
}
/*
    return the kth permutation
*/
string getPermutation(int n, int k) {
    // the factorial val of 0-9
    int factorials[10] = {1,1,2,6,24,120,720,5040,40320,362880};
    string ans = "";
    vector<int> v {};
    for(int i = 1; i <= n; i++){
        v.push_back(i);
    }
    helper(v, factorials, k, ans);
    return ans;

}

int main(){
    cout<<getPermutation(4,9);
}
