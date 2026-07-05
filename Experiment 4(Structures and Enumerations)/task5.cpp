/*A phone number can be stored as three parts: area code, exchange, and number. Write a struct 
PhoneNumber to hold these. Initialize one number in code, read a second from the user, and 
display both in the format (NNN) NNN-NNNN. */
#include <iostream>
using namespace std;
struct PhoneNumber{
    int areaCode;
    int exchange;
    int number;
};
void display(PhoneNumber p){
    cout << "(" << p.areaCode << ") "
         << p.exchange << "-"
         << p.number << endl;
}
int main(){
    PhoneNumber p1 = {923, 123, 4567};

    PhoneNumber p2;
    cout << "Enter second phone number details:\n";
    cout << "Area code: ";
    cin >> p2.areaCode;
    cout << "Exchange: ";
    cin >> p2.exchange;
    cout << "Number: ";
    cin >> p2.number;

    cout << "\n===== Phone Numbers =====\n";
    cout << "First number  : ";
    display(p1);
    cout << "Second number : ";
    display(p2);

    return 0;
}