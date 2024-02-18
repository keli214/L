#include <vector>
#include <iostream>
#include <unordered_set>
#include "math.h"

using namespace std;
double epsilon = 1e-5;
bool test = false;
vector<char> operators {'*', '+', '-', '/'};
void helper(vector<double>& cards){
    //base case: [24]
    if(cards.size()==1){
        if(abs(cards[0] - 24) <= epsilon){
            test = true;
        }
        return;
    }
    for(int i = 0; i < cards.size(); i++){
        for(int j = 0; j < cards.size(); j++){
            if(i == j )continue;
            vector<double> next;
            for(int k = 0; k < cards.size(); k++){
                if(k != i && k != j)
                    next.push_back(cards[k]);
            }
            for(auto opr: operators){
                if(i > j && (opr == '*' || opr == '+')) 
                    continue;
                if(opr == '/' && cards[j] == 0.0)
                    continue;
                switch (opr)
                {
                case '+':
                    next.push_back(cards[i] + cards[j]);
                    break;
                case '-':
                    next.push_back(cards[i] - cards[j]);
                    break;
                case '*':
                    next.push_back(cards[i] * cards[j]);
                    break;
                case '/':
                    next.push_back(cards[i] / cards[j]);
                    break;
                }
                helper(next);
                if(test)
                    return;
                next.pop_back();
            }
        }
        
    }

}
bool judgePoint24(vector<int>& cards) {
    vector<double> copy;
    for(auto i : cards){
        copy.push_back(i);
    }
    helper(copy);
    return test;
}

int main(){
    vector<int> nums {4,1,8,7};
    cout<<judgePoint24(nums);
    return 0;
}