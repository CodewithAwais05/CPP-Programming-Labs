/*Write a function void swapByRef(int &a, int &b) that swaps two integers using pass-by
reference, and a separate function void swapByPtr(int *a, int *b) that performs the same swap 
using pass-by-pointer. Call both in sequence on the same pair of variables and print the values 
after each call to confirm they behave identically. Then overload swapByRef for doubles and 
strings, and explain in a comment one situation where pass-by-pointer is preferable to pass
by-reference.*/
#include <iostream>
using namespace std;
void swapByRef(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void swapByRef(double &a, double &b){
    double temp = a;
    a = b;
    b = temp;
}
void swapByRef(string &a, string &b){
    string temp = a;
    a = b;
    b = temp;
}
void swapByPtr(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int x = 10, y = 20;
    cout << "Before Swapping: x = " << x << ", y = " << y << endl;
    swapByRef(x, y);
    cout << "swapByRef: x = " << x << ", y = " << y << endl;
    
    swapByPtr(&x, &y);
    cout << "swapByPtr: x = " << x << ", y = " << y << endl;
    
    double d1 = 1.5, d2 = 3.7;
    cout << "\nBefore Swapping: d1 = " << d1 << ", d2 = " << d2 << endl;
    swapByRef(d1, d2);
    cout << "swapByRef(Double): " << d1 << ", " << d2 << endl;

    string s1 = "Hello", s2 = "World";
    cout << "Before Swapping: " << s1 << ", " << s2 << endl;
    swapByRef(s1, s2);
    cout << "swapByRef(String): " << s1 << ", " << s2 << endl;

    return 0;
}
/*
Pass-by-pointer is preferable in situations where:

1. The function must accept NULL (nullptr) to indicate "no object"
   or optional parameters.
2. When dealing with dynamic memory, pointers are required (e.g., arrays).
Pass-by-reference is safer and cleaner for normal use because it:
- Cannot be null
- Has simpler syntax
So:
-> Use reference for most C++ code
-> Use pointer when nullability or low-level memory control is needed
*/