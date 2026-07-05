/*Write a program that repeatedly reads an integer from the user and uses a switch statement to 
print its English name for any value from 1 (One) through 12 (Twelve); any other value 
should be reported as "Other" along with whether it is even or odd. Keep reading until the 
user enters 0, then print how many valid (1-12) and how many "Other" values were entered.*/

#include<iostream>
using namespace std;
int main(){
    int num;
    int valid_count = 0, other_count = 0;
    while(true){
        cout << "Enter number(1-12)(0 to quite):  ";
        cin >> num;
        if(num == 0){
            break;
        }
        switch(num)
        {
            case 1:
                cout << "One";
                valid_count++;
                break;
            case 2:
                cout << "Two";
                valid_count++;
                break;
            case 3:
                cout << "Three";
                valid_count++;
                break;
            case 4:
                cout << "Four";
                valid_count++;
                break;
            case 5:
                cout << "Five";
                valid_count++;
                break;
            case 6:
                cout << "Six";
                valid_count++;
                break;
            case 7:
                cout << "Seven";
                valid_count++;
                break;
            case 8:
                cout << "Eight";
                valid_count++;
                break;
            case 9:
                cout << "Nine";
                valid_count++;
                break;
            case 10:
                cout << "Ten";
                valid_count++;
                break;
            case 11:
                cout << "Eleven";
                valid_count++;
                break;
            case 12:
                cout << "Twelve";
                valid_count++;
                break;
            default:
                cout << "Other";
                if(num % 2 == 0){
                    cout << " (Even)";
                }
                else{
                    cout << " (Odd)";
                }
                other_count++;
        }
        cout << endl;
    }
    cout << "\n================Counts================\n";
    cout << "Valid:  " << valid_count << endl;
    cout << "Others:  " << other_count << endl;
}