#include <vector>
#include <iostream>
#include <stack>

using namespace std;
/*
    Using stack to keep track of the asteroids and check the top of the stack if a 
    opposite sign asteroid is encountered
    negative <- -> positive 
    if the curr asteroid is going to the right, it will never encounter previous asteriod that's going to the left
    but if curr is going to the left, it will encounter previous ones that's going to the right 

*/
bool noCollision(const int& top, const int& b){
    //if they have the same sign or the top is going left 
    return ((top < 0 && b < 0) || (top > 0 && b > 0) || (top < 0 && b > 0));
}

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> curr;
    for(auto a: asteroids){
        if(curr.empty() || noCollision(curr.top(), a)){
            curr.push(a);
        }
        else{
            //if there is a collision
            //check if the top is smaller than the asteriod
            while(!curr.empty() && !noCollision(curr.top(), a) && abs(curr.top()) < abs(a)){
                curr.pop();
            }
            if(!curr.empty() && !noCollision(curr.top(),a) && abs(curr.top()) == abs(a)){
                curr.pop();
                continue;
            }
            //if all the asteriods are less than a -> empty stack
            //if the top of the stack is going the same dir as a 
            if(curr.empty() || (!curr.empty() && noCollision(curr.top(),a))){
                curr.push(a);
            }
        }
    }
    vector<int> res;
    while(!curr.empty()){
        res.insert(res.begin(), curr.top());
        curr.pop();
    }
    return res;
}

int main(){
    vector<int> asteriods {-8, 8};
    vector<int> res = asteroidCollision(asteriods);
    for(auto a: res){
        cout<<a<<" ";
    }
}