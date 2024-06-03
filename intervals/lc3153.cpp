#include <vector>
#include <iostream>

using namespace std;

long long sumDigitDifferences(vector<int>& nums) {
    int digits = 0, a = nums[0];
    while(a){
        a /= 10;
        ++digits;
    }
    vector<vector<int>> m(digits, vector<int>(10, 0));
    for(auto &i: nums){
        for(int d = 0; d < digits; ++d){
            ++m[d][i%10];
            i /= 10;
        }
    }    
    
    long long res {0};
    for(const auto &c: m){
        for(int i = 0; i < 10; ++i){
            for(int j = i+1; j < 10; ++j){
                res += c[i]*c[j]*(j-i);
                cout<<res<<endl;
            }
        }
    }
    return res;
}

int main(){
    vector<int> nums{50,28,48};
    cout<<sumDigitDifferences(nums);

}