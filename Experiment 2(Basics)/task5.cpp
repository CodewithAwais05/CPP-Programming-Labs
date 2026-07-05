/*Write a program that reads a temperature in Celsius and converts it to both Fahrenheit and 
Kelvin. The formulas are: F = (C * 9/5) + 32 and K = C + 273.15. Display results with exactly 
two decimal places using setprecision.*/
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    double Celcius;
    cout << "Enter temperature in Celcius:   ";
    cin >> Celcius;

    cout << "Fahrenheit:  " << (Celcius * 9 / 5) + 32 << endl;
    cout << "Kelvin:  " << Celcius + 273.15 << endl;
}