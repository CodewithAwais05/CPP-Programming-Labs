/*Write a program that reads a student name (single word), age, and GPA from the user. 
Display all three values in a right-aligned table using setw(). Include column headers. */
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main(){
    string name;
    int age;
    float GPA;
    cout << "Enter Name of student:  ";
    cin >> name;
    cout << "Enter age of student:  ";
    cin >> age;
    cout << "Enter GPA of student:  ";
    cin >> GPA;

    cout << "\n===============Data===============\n";
    cout << setw(12) << "Name" << setw(12) << right << "Age" << setw(12) << "GPA\n";
    cout << setw(12) << name << setw(12) << age << setw(12) << GPA << endl;

    return 0;
}