#include <vector>
#include <iostream>

using namespace std;

vector<int> addToArrayForm(vector<int>& num, int k) {
    int carry = 0;
    for(int i = num.size()-1; i >= 0; i--){
        int d = k % 10;
        int tmp = num[i] + d + carry;
        carry = tmp >= 10 ? 1 : 0;
        k /= 10;
        num[i] = tmp%10;
    }
    if(carry == 1){
        num.insert(num.begin(), 1);
    }
    return num;
}

int main(){
    vector<int> num{1,2,0,0};
    int k = 34;
    addToArrayForm(num, k);
    for(auto i: num){
        cout<<i;
    }
}

