#include <vector>
#include <iostream>
#include <stack>

using namespace std;
/*
    Given two integer arrays pushed and popped each with distinct values, 
    return true if this could have been the result of a sequence of push and pop operations 
    on an initially empty stack, or false otherwise.

    pushed = [1,2,3,4,5], popped = [4,5,3,2,1]

    Using a stack to simulate the pop and pushed operation

*/


bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> s;
    int j = 0;
    for(int val: pushed){
        s.push(val);
        while(!s.empty() && s.top() == popped[j]){
            s.pop();
            j++;
        }
    }
    return s.empty();
}

int main(){
    vector<int> pushed = {1,2,3,4,5}, popped = {4,5,3,2,1};
    cout<<validateStackSequences(pushed, popped);
}