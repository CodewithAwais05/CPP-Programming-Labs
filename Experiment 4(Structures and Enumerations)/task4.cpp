/*Create an enum named Month with values January through December (values 1 through 12). 
Read an integer from the user. Using a switch statement, print the corresponding month name 
and the number of days in that month (assume a non-leap year).*/
#include<iostream>
enum Month{
    January = 1, February, March, April, May, June, July, August, September, October, November, December
};
using namespace std;
int main(){
    int m;
    cout << "Enter month number:  ";
    cin >> m;
    Month month = static_cast<Month>(m);
    switch(month){
        case January:
            cout << "January - 31 Days\n";
            break;
        case February:
            cout << "February - 28 Days\n";
            break;
        case March:
            cout << "March - 31 Days\n";
            break;
        case April:
            cout << "April - 30 Days\n";
            break;
        case May:
            cout << "May - 31 Days\n";
            break;
        case June:
            cout << "June - 30 Days\n";
            break;
        case July:
            cout << "July - 31 Days\n";
            break;
        case August:
            cout << "August - 31 Days\n";
            break;
        case September:
            cout << "September - 30 Days\n";
            break;
        case October:
            cout << "October - 31 Days\n";
            break;
        case November:
            cout << "November - 30 Days\n";
            break;
        case December:
            cout << "December - 31 Days\n";
            break;
        default:
            cout << "Invalid Month number.\n";
    }
    return 0;
}