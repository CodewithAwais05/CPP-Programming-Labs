/*Write a program that reads the radius of a circle from the user and prints its area, 
circumference, and the diameter. Use a const double for PI. */
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    const double PI = 3.1416;
    float radius;
    cout << "Enter Radius of circle:  ";
    cin >> radius;

    cout << "Area:  " << PI*radius*radius << endl;
    cout << "Diameter:  " << 2*radius << endl;
    cout << "Circumference:  " << 2*PI*radius << endl;

    return 0;
}