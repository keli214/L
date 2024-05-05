#include <string>
#include <iostream>
#include <vector>

using namespace std;

/*
    compare the two version number, ignore the trailing 0s 
    if version1 < version2, return -1 
    if version1 > version2, return 1 
    else return 0

    parse and compare the version one by one 
    

*/
int compareVersion(string version1, string version2) {
    size_t i = 0, j = 0, n = version1.size(), m = version2.size();
    while(i < n || j < m){
        int num1 = 0, num2 = 0;
        while(i < n && version1[i] != '.'){
            num1 = num1*10 + version1[i]-'0';
            ++i;
        }
        while(j < m && version2[j] != '.'){
            num2 = num2*10 + version2[j]-'0';
            ++j;
        }
        if(num1 > num2){
            return 1;
        }
        else if(num1 < num2){
            return -1;
        }
        i++;
        j++;
    }
    return 0;
    
}

int main(){
    string v1 = "1.0.1", v2 = "1";
    cout<<compareVersion(v1, v2);
}