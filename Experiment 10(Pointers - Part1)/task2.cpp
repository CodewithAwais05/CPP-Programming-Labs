/*Write swapNums(int *a, int *b) using pointer parameters. Demonstrate it swapping three 
different pairs. Also implement the XOR swap: *a ^= *b; *b ^= *a; *a ^= *b; and verify it 
produces the same result as the temp-based version.*/
#include <iostream>
using namespace std;
void swapNums(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void xorSwap(int *a, int *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
int main(){
    int a = 10, b = 20;
    int e = 50, f = 60;

    cout << "Temp Swapping\n";
    cout << "Before: a = " << a << ", b = " << b << endl;
    swapNums(&a, &b);
    cout << "After : a = " << a << ", b = " << b << endl;

    cout << "\nXOR Swapping\n";
    cout << "Before: e = " << e << ", f = " << f << endl;
    xorSwap(&e, &f);
    cout << "After : e = " << e << ", f = " << f << endl;

    return 0;
}