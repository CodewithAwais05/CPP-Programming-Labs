/*Declare five separate named int variables and a matching array of five int* pointers, each 
initialized to the address of one variable. Print the value and address of each variable through 
its pointer, then compute and print the difference between each consecutive pair of addresses 
 (cast to a common integer type) to confirm whether the compiler placed them contiguously in 
memory. Repeat the experiment with five separate double variables and explain in a comment 
why the address gaps differ between the two cases.*/
#include <iostream>
using namespace std;
int main(){
    int a = 10, b = 20, c = 30, d = 40, e = 50;
    int* intPtr[5] = {&a, &b, &c, &d, &e};
    cout << "Integer Variables\n";
    for (int i = 0; i < 5; i++){
        cout << "Value = " << *intPtr[i] << "  Address = " << intPtr[i] << endl;
    }
    cout << "\nAddress Differences for integers\n";
    for (int i = 0; i < 4; i++){
        cout << (char*)intPtr[i + 1] - (char*)intPtr[i] << " bytes" << endl;
    }

    double p = 1.1, q = 2.2, r = 3.3, s = 4.4, t = 5.5;
    double* doublePtr[5] = {&p, &q, &r, &s, &t};
    cout << "\nDouble Variables\n";
    for (int i = 0; i < 5; i++){
        cout << "Value = " << *doublePtr[i] << "  Address = " << doublePtr[i] << endl;
    }
    cout << "\nAddress Differences for doubles\n";
    for (int i = 0; i < 4; i++){
        cout << (char*)doublePtr[i + 1] - (char*)doublePtr[i] << " bytes" << endl;
    }

    // int usually takes 4 bytes and double usually takes 8 bytes,
    // so the address gaps for doubles are generally larger.
    // However, separate variables are not guaranteed to be stored contiguously in memory.

    return 0;
}