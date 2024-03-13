#include <vector>
#include <string>
#include <iostream>

using namespace std;

/*
    Check if curr[start:end](inclusive) is a valid sub ip address
*/
bool isValid(string s, int start, int end){
    //leading 0s
    if(s[start]=='0' && end != start)
        return false; 
    //longer than 3
    if(end-start+1 > 3)
        return false; 
    int digit = stoi(s.substr(start, end-start+1));
    return !(digit > 256 || digit < 0);
}

/*
    "25525511135" 
    "255.255.11.135"
*/
void helper(vector<string>& valid, string& curr, string s, int start, int delimiter){
    for(int end = start; end < s.size(); end++){
        if(delimiter == 3){
            if(isValid(s, start, s.size()-1)){
                curr += s.substr(start);
                valid.emplace_back(curr);
                return;
            }
        }
        else if (isValid(s, start, end)){
            string temp = curr;
            curr += s.substr(start,end-start+1) + ".";
            helper(valid, curr, s, end+1, delimiter+1);
            curr = temp;
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> valid;
    string curr = "";
    helper(valid,curr, s, 0, 0);
    return valid;
}

int main(){
    string s = "101023";
    vector<string> res =restoreIpAddresses(s);
    for(auto ip: res){
        cout<<ip<<endl;
    }
}