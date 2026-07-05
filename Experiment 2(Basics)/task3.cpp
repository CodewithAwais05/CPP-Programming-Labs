/*Write a program that declares one variable of every fundamental type (int, short, long, long 
long, float, double, char, bool). Assign appropriate values and print both the value and the size 
in bytes using sizeof().*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i = 25;
    short s = 10;
    long l = 100000L;
    long long ll = 1234567890123LL;
    float f = 3.14f;
    double d = 3.1415926535;
    char c = 'A';
    bool b = true;

    cout << "Data Type\tValue\t\tSize (bytes)" << endl;
    cout << "--------------------------------------------" << endl;

    cout << "int\t\t" << i << "\t\t" << sizeof(i) << endl;
    cout << "short\t\t" << s << "\t\t" << sizeof(s) << endl;
    cout << "long\t\t" << l << "\t\t" << sizeof(l) << endl;
    cout << "long long\t" << ll << "\t" << sizeof(ll) << endl;
    cout << "float\t\t" << f << "\t\t" << sizeof(f) << endl;
    cout << "double\t\t" << d << "\t\t" << sizeof(d) << endl;
    cout << "char\t\t" << c << "\t\t" << sizeof(c) << endl;
    cout << "bool\t\t" << b << "\t\t" << sizeof(b) << endl;

    return 0;
}