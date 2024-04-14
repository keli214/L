#include <vector>
#include <iostream>
using namespace std;
/*
    sort the hand and pick cards to form groups
*/
bool isNStraightHand(vector<int>& hand, int groupSize) {
    //check if hand is divisible by groupSize
    if(hand.size() % groupSize != 0){
        return false;
    }
    sort(hand.begin(), hand.end());

    int target = hand.size() / groupSize;

    vector<vector<int>> groups(target);

    for(int i = 0; i < hand.size(); i++){
        int j = 0;
        for( ; j < groups.size(); j++){
            if(groups[j].size() == groupSize)
                continue;
            if(groups[j].empty() || groups[j].back() + 1 == hand[i]){
                groups[j].push_back(hand[i]);
                break;
            }
        }
        if(j == groups.size()){
            return false;
        }
    }

    return true;
    
}

int main(){
    vector<int> hand{1,2,3,6,2,3,4,7,8};
    int groupSize = 3;
    cout<<isNStraightHand(hand, groupSize);
}