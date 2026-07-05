/*Write a calculator program that repeatedly reads two integers and an operator character (+, -, 
*, /, %) until the user enters 'q'. For each entry, reject division and modulus by zero with an 
error message instead of crashing, perform the requested operation, and also display the result 
of dividing the first operand by the second as a double with two decimal places. After the loop 
ends, report how many times each operator was used.*/
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int num1, num2;
    char op, choice ;
    int A_count = 0, S_count = 0, D_count = 0, Mul_count = 0, Mod_count = 0;
    do{
        cout << "Enter first number:  ";
        cin >> num1;
        cout << "Enter seocnd number:  ";
        cin >> num2;
        cout << "Enter operation(+, -, /, *, %):  ";
        cin >> op;

        switch (op)
        {
        case '+':
            cout << "Addition of both numbers is:  " << num1 + num2 << endl;
            A_count++;
            break;
        case '-':
            cout << "Subtraction of both numbers is:  " << num1 - num2 << endl;
            S_count++;
            break;
        case '*':
            cout << "Multiplication of both numbers is:  " << num1 * num2 << endl;
            Mul_count++;
            break;
        case '/':
            if(num2 == 0){
                cout << "Division by zero is not possible" << endl;
            }
            else{
                cout << "Division of both numbers is:  " << (double)num1 / num2 << endl;
            }
            D_count++;
            break;
        case '%':
            if(num2 == 0){
                cout << "Division by zero is not possible" << endl;
            }
            else{
                cout << "Modulus of both numbers is:  " << num1 % num2 << endl;
            }
            Mod_count++;
            break;
        
        default:
            cout << "Invalid Operator\n";
            break;
        }

        cout << "Continue? (q to Quite) :  ";
        cin >> choice;
    }while(choice != 'q');

    cout << "\n\n============Number of times the Operations called============\n";
    cout << "+ :  " << A_count << " times.\n";
    cout << "- :  " << S_count << " times.\n";
    cout << "* :  " << Mul_count << " times.\n";
    cout << "/ :  " << D_count << " times.\n";
    cout << "% :  " << Mod_count << " times.\n";
    cout << "\n===============================================================\n";

    return 0;
}