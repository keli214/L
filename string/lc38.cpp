#include <iostream>

using namespace std;

string countAndSay(int n) {
    //invalid inputs
    if(n<1)
        return "";
    //base case
    if(n==1)
        return "1";
    string input = countAndSay(n-1), res = "";
    int i = 0;
    while (i < input.size()){
        int j = i; 
        while(j < input.size() && input[i] == input[j]){
            j++;
        }
        res += to_string(j-i) + input[i];
        i = j == i ? i+1 : j;
    }
    return res;

}

int main(){
    //n = 1
    //1
    //n = 2
    //11
    //n = 3
    //21
    //n=4
    //1211
    int n = 4;
    cout<<countAndSay(n);
    return 0;
}