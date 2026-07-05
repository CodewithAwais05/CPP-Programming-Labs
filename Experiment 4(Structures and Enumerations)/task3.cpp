/*Create a nested structure: an Address structure (street, city, postalCode) and a Person structure 
that contains an Address as a member. Read a person record and print a formatted address 
label. */
#include<iostream>
using namespace std;
struct Address{
    string street;
    string city;
    string postalCode;
};

struct Person{
    Address add;
    string name;
};
int main(){
    Person p;
    cout << "Enter Person Details:  \n";
    cout << "Enter name:  ";
    getline(cin, p.name);
    cout << "Enter street:  ";
    getline(cin, p.add.street);
    cout << "Enter City:  ";
    getline(cin, p.add.city);
    cout << "Enter Postal Code:  ";
    getline(cin, p.add.postalCode);

    cout << p.name << endl;
    cout << p.add.street << endl;
    cout << p.add.city << " - " << p.add.postalCode << endl;

}