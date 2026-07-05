/*Write a function double power(double base, int exp = 2) with a default exponent. Also 
overload it as double power(double base, double exp) that uses the standard pow() function 
from <cmath>. Call both versions. */
#include <iostream>
#include <cmath>
using namespace std;
double power(double base, int exp = 2){
    double result = 1;
    for (int i = 1; i <= exp; i++){
        result *= base;
    }
    return result;
}
double power(double base, double exp){
    return pow(base, exp);
}
int main(){
    double base = 5;
    cout << "power(5) = " << power(base) << endl;

    cout << "power(5, 3) = " << power(base, 3) << endl;

    cout << "power(5, 2.5) = " << power(base, 2.5) << endl;

    return 0;
}