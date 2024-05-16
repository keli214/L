#include <vector>
#include <iostream>

using namespace std;

/*
    sort the happiness then add k values with each decrement by k-1
*/
long long maximumHappinessSum(vector<int>& happiness, int k) {
    long long res = 0;
    sort(happiness.begin(), happiness.end(), greater<int>());
    for(int i = 0; i < k; i++){
        res += happiness[i] - i;
    }
    return res;
}

