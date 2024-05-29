#include <iostream>
#include <string>

using namespace std;

// int numSteps(string s) {
//     int res = 0;
//     while(s.size() > 1){
//         cout<<s<<endl;
//         if(s.back() == '0'){
//             s.erase(s.size()-1);
//         }else{
//             int carry = 1;
//             for(int i = s.size()-1; i >= 0; --i){
//                 if(s[i] == '1' && carry)
//                     s[i] = '0';
//                 else if(s[i] == '0' && carry){
//                     s[i] = '1';
//                     carry = 0;
//                 }
//             }
//             if(carry)
//                 s = '1' + s;
//         }
//         res ++;
//     }
//     return res;
// }


int numSteps(string s){
    int i = s.size()-1, res = 0, carry = 0;
    while(i >= 0){
        if(s[i] == '0'){
            if(carry == 1){
                s[i] = '1';
                carry = 0;
            }
            else{
                res ++;
            }
        }else{
            if(i == 0){
                return res + 1;
            }
            while(i >= 0 && s[i] == '1'){
                res ++;
                i--;
            }
            res++;
            carry = 1;
            cout<<res<<endl;
        }
    }
    return res;
}

int main(){
    string s {"1001"};
    cout<<numSteps(s);
}