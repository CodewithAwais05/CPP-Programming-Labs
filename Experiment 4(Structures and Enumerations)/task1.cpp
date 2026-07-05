/*Define a struct named Mixed that contains one member of every fundamental type (int, short, 
long, float, double, char, bool). Create an array of three Mixed variables with different values, 
print each variable's members and the size of the whole struct using sizeof(Mixed), then 
compute and print the sum of the individual sizeof() values of its members. Explain in a 
comment why the two totals are not necessarily equal (structure padding).string */
#include <iostream>
using namespace std;
struct Mixed
{
    int i;
    short s;
    long l;
    float f;
    double d;
    char c;
    bool b;
};

int main()
{
    Mixed arr[3] = {
        {10, 1, 1000, 3.5f, 2.71, 'A', true},
        {20, 2, 2000, 4.5f, 6.28, 'B', false},
        {30, 3, 3000, 5.5f, 9.10, 'C', true}
    };

    cout << "===== Structure Values =====\n\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "Object " << i + 1 << ":\n";
        cout << "int    : " << arr[i].i << endl;
        cout << "short  : " << arr[i].s << endl;
        cout << "long   : " << arr[i].l << endl;
        cout << "float  : " << arr[i].f << endl;
        cout << "double : " << arr[i].d << endl;
        cout << "char   : " << arr[i].c << endl;
        cout << "bool   : " << arr[i].b << endl;
        cout << endl;
    }

    cout << "Size of struct Mixed = " << sizeof(Mixed) << " bytes\n";

    int sum = sizeof(int) + sizeof(short) + sizeof(long) +
              sizeof(float) + sizeof(double) +
              sizeof(char) + sizeof(bool);

    cout << "Sum of member sizes  = " << sum << " bytes\n";

    //Both totals are not equal because of "PADDING" , it is the extra space added by compiler to align the data properly in the memory

    return 0;
}