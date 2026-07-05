/*Write a function int gcd(int a, int b) that computes the greatest common divisor using 
recursion (Euclidean algorithm). Then write int lcm(int a, int b) that uses gcd. Test with 
several pairs.*/
#include<iostream>
using namespace std;
int GCD(int a, int b){
    if(b == 0){
        return a;
    }
    return GCD(b, a % b);
}
int lcm(int a, int b){
    return (a * b) / GCD(a, b);
}
int main(){
    cout << "GCD(12, 18) = " << GCD(12, 18) << endl;
    cout << "LCM(12, 18) = " << lcm(12, 18) << endl;

    cout << "GCD(7, 5) = " << GCD(7, 5) << endl;
    cout << "LCM(7, 5) = " << lcm(7, 5) << endl;

    cout << "GCD(100, 25) = " << GCD(100, 25) << endl;
    cout << "LCM(100, 25) = " << lcm(100, 25) << endl;
}