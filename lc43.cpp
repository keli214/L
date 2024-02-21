#include <string>
#include <iostream>

using namespace std;
string add(string a, string b){
    string res = "";
    int carry = 0;
    int minLen = a.size() <= b.size() ? a.size() : b.size();
    int maxLen = a.size() > b.size() ? a.size() : b.size();
    for(int i = 0; i < minLen; i++){
        int sum = (a[i]-'0') + (b[i]-'0') + carry;
        res += to_string(sum%10);
        carry = sum/10;
    }
    
    string maxStr = a.size() > b.size() ? a : b;
    for(int i = minLen; i < maxLen; i++){
        int sum = (maxStr[i]-'0') + carry;
        res += to_string(sum%10);
        carry = sum/10;
    }
    if(carry){
        res += '1';
    }
    return res;
}
string multiply(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    string res = "";
    string maxNum = num1.size() > num2.size() ? num1 : num2;
    string minNum = num1.size() <= num2.size() ? num1 : num2;
    for(int i = 0; i < minNum.size(); i++){
        int carry = 0, m = minNum[i]-'0';
        string curr = string(i, '0');
        for(int j = 0; j < maxNum.size(); j++){
            int n = maxNum[j]-'0';
            curr += to_string((m*n + carry)%10);
            carry = (m*n + carry)/10;
        }
        if(carry)
            curr += to_string(carry);
        res = add(curr, res);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    string a = "9", b = "9";
    cout<<multiply(a,b);
}