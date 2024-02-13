#include <iostream>
using namespace std;

int divide(int dividend, int divisor) {
    // count the number of times that divisor can shift left 
    // until resulting in zero when substracted from divident
    // ex: 10/3 = 3
    // 3 << 1 = 6, 6 << 1 = 12 
    // m = 2
    // 10 - 6 = 4
    // 4 >= 3


    // get the sign of the result
    int sign = 1;
    if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
        sign = -1;
    //edge case where INT_MIN = -2147483648 
    //-2147483648/-1 = 2147483647
    if(dividend == INT_MIN && (divisor == -1 || divisor == 1)){
        return INT_MAX;
    }
    // first conver both inputs to positive integer
    long abs_dividend = labs(dividend);
    long abs_divisor = labs(divisor);
    cout<<abs_dividend<<" "<<abs_divisor<<endl;

    int res = 0;
    while(abs_dividend >= abs_divisor){
        long m = 1, tmp = abs_divisor;
        // cout<<abs_dividend<<" "<<tmp<<endl;
        // left shift the divisor until divisor is larger than divident
        while((tmp<<1) <= abs_dividend){
            tmp <<= 1;
            m <<= 1;
            // cout<<abs_dividend<<" "<<tmp<<endl;
        }
        cout<<abs_dividend<<" outer "<<abs_divisor<<endl;
        res += m;
        abs_dividend -= tmp;
    }
    return res*sign;
}

int main()
{
    //-1
    //1
    int a =INT_MAX, b = 1;
    cout<<divide(a,b);
}