/*
An integer x.
Record a new score of x.
'+'.
Record a new score that is the sum of the previous two scores.
'D'.
Record a new score that is the double of the previous score.
'C'.
Invalidate the previous score, removing it from the record.
Return the sum of all the scores on the record after applying all the operations.
*/
#include <vector>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

int calPoints(vector<string>& operations) {
    stack<int> s;
    for(auto &opr: operations){
        if(opr == "+"){
            int t = s.top();
            s.pop();
            int sum = t + s.top();
            s.push(t);
            s.push(sum);
        }
        else if(opr == "D"){
            s.push(s.top()*2);
        }
        else if(opr == "C"){
            s.pop();
        }
        else{
            s.push(stoi(opr));
        }
    } 
    int res = 0;
    while(!s.empty()){
        res += s.top();
        s.pop();
    }   
    return res;
}

int main(){
    vector<string> ops {"1","C"};
    cout<<calPoints(ops);
}