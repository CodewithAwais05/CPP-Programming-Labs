/*Write a recursive function int sumDigits(int n) that returns the sum of all digits of a positive 
integer. For example, sumDigits(1234) should return 10. Test it with at least five values. */
#include <iostream>
using namespace std;
int sumDigits(int n){
    if (n == 0)
        return 0;
    return (n % 10) + sumDigits(n / 10);
}
int main(){

    cout << "sumDigits(1234) = " << sumDigits(1234) << endl;
    cout << "sumDigits(9876) = " << sumDigits(9876) << endl;
    cout << "sumDigits(505)  = " << sumDigits(505) << endl;
    cout << "sumDigits(1)    = " << sumDigits(1) << endl;
    cout << "sumDigits(99999)= " << sumDigits(99999) << endl;

    return 0;
}