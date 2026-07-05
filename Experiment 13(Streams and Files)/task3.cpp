/*Write five EmployeeRecord structs to a binary file. Read them all back and display them. 
Then update the salary of the employee at index 2 using seekp and read it back using seekg to 
confirm the change*/
#include <iostream>
#include <fstream>
using namespace std;
struct EmployeeRecord{
    int id;
    char name[30];
    float salary;
};
int main(){
    EmployeeRecord emp[5];
    cout << "Enter details of 5 employees:\n";
    for (int i = 0; i < 5; i++){
        cout << "\nEmployee " << i + 1 << endl;
        cout << "ID: ";
        cin >> emp[i].id;
        cout << "Name: ";
        cin >> emp[i].name;
        cout << "Salary: ";
        cin >> emp[i].salary;
    }
    ofstream fout("employees.dat", ios::binary);
    for (int i = 0; i < 5; i++){
        fout.write((char*)&emp[i], sizeof(EmployeeRecord));
    }
    fout.close();
    ifstream fin("employees.dat", ios::binary);
    cout << "\nEmployee Records:\n";
    cout << "---------------------------------\n";

    EmployeeRecord temp;
    while (fin.read((char*)&temp, sizeof(EmployeeRecord))){
        cout << "ID: " << temp.id << endl;
        cout << "Name: " << temp.name << endl;
        cout << "Salary: " << temp.salary << endl;
        cout << "---------------------------------\n";
    }

    fin.close();
    fstream file("employees.dat", ios::in | ios::out | ios::binary);
    EmployeeRecord update;
    file.seekg(2 * sizeof(EmployeeRecord), ios::beg);
    file.read((char*)&update, sizeof(EmployeeRecord));
    cout << "\nCurrent Salary of Employee at Index 2: "
         << update.salary << endl;
    cout << "Enter New Salary: ";
    cin >> update.salary;

    file.seekp(2 * sizeof(EmployeeRecord), ios::beg);
    file.write((char*)&update, sizeof(EmployeeRecord));

    file.seekg(2 * sizeof(EmployeeRecord), ios::beg);
    file.read((char*)&update, sizeof(EmployeeRecord));

    cout << "\nUpdated Record:\n";
    cout << "ID: " << update.id << endl;
    cout << "Name: " << update.name << endl;
    cout << "Salary: " << update.salary << endl;

    file.close();

    return 0;
}