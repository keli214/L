#include <string>
#include <iostream>

using namespace std;
/*
    "111000"->"101010","010101"
    "110"->"101"
    If alternating string:
        all 1s are at even/odd indicies, 0s are at odd/even indicies
    If the string is even length, the min changes:
        min(abs(n-zerosE-onesO)), abs(n-onesE-zerosO))
    If the string is odd length:
        swap the even and odd zeros and ones
        if the first char is 0:
            even0 ++, odd0 --
        else
            even1 ++, odd1 --

*/

int minFlips(string s) {
    //count 1s and 0s and check if s is alternating
    int count = 0, zerosE = 0, onesE = 0, 
        zerosO = 0, onesO = 0, n = s.size();
    char prev = '*';
    for(int i = 0; i < n; i++){
        if((i%2)==0){
            zerosE += s[i] == '0';
            onesE += s[i] == '1';
        }
        else{
            zerosO += s[i] == '0';
            onesO += s[i] == '1';
        }
        count += prev == s[i];
        prev = s[i];
    }  
    if(count == 0) 
        return 0;
    count = INT_MAX;
    if(n%2 == 0 ){
        count = min(count, abs(n-zerosE-onesO));
        count = min(count, abs(n-zerosO-onesE));
    }else{
        count = min(count, abs(n-zerosE-onesO));
        count = min(count, abs(n-zerosO-onesE));
        //shift one position
        for(int i = 0; i < s.size()-1; i++){
            if(s[i] == '0'){
                swap(zerosE, zerosO);
                zerosE ++;
                zerosO --;
                swap(onesE, onesO);
            }
            else{
                swap(onesE, onesO);
                onesE ++;
                onesO --;
                swap(zerosE, zerosO);
            }
            count = min(count, abs(n-zerosE-onesO));
            count = min(count, abs(n-zerosO-onesE));
        }
    }
    
    return count;
}

int main(){
    string a = "01001001101";
    cout<<minFlips(a);
}