#include <string>
#include <iostream>

using namespace std;

/*
    use backtracking to explore all possible combinations
    if there are open paren after *, we can't use those * as ( to cancel them
*/

bool helper(string s, int open, int idx){
    if(idx == s.size()){
        return open == 0;
    }
    if(s[idx] == '*'){
        if(open > 0){
            return (helper(s, open, idx+1) || helper(s, open+1, idx+1) || helper(s, open-1, idx+1));
        }
        else{
            return (helper(s, open, idx+1) || helper(s, open+1, idx+1));
        }
    }
    else if(s[idx] == '('){
        return helper(s, open+1, idx+1);
    }
    else{//)
        if (open > 0){
            return helper(s, open-1, idx+1);
        }
        return false;
    }
    return false;
}

bool checkValidString(string s) {
    int open = 0, count = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            open ++;
            count ++;
        }
        else if(s[i] == ')'){
            open --;
            count --;
        }
        else{//*
            open ++;
            count --;
        }
        if(open < 0){
            return false;
        }
        count = max(count, 0);
    }
    return count == 0;
}

int main(){
    string s = "(****((";
    cout<<checkValidString(s);

}