#include <iostream>
#include <string>

using namespace std;

string breakPalindrome(string palindrome) {
    size_t i = 0, n = palindrome.size();
    string res = "";
    while(i < n/2){
        if(i-'a' != 0){
            palindrome[i] = 'a';
            return palindrome;
        }
    }
    if(n > 1){
        palindrome[n-1] ++;
        return palindrome;
    }
    return res;
}

int main(){
    string s = "aa";

}