/*Write an Employee class whose constructor allocates the employee's name on the heap with 
new char[] and copies the supplied name into it, and whose destructor frees that memory with 
 delete[]. Create an array of at least three Employee pointers, allocate each object with new, 
populate it through the pointer, print all records using the arrow operator, then explicitly 
delete every object in the array. */
#include <iostream>
#include <cstring>
using namespace std;
class Employee{
private:
    char *name;
    int id;
    double salary;
public:
    Employee(const char *n, int i, double s){
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        id = i;
        salary = s;
    }
    ~Employee(){
        delete[] name;
        cout << "Memory for " << id << " deallocated." << endl;
    }
    void display(){
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "------------------------" << endl;
    }
};
int main(){
    Employee *emp[3];

    emp[0] = new Employee("Awais", 101, 50000);
    emp[1] = new Employee("Ali", 102, 60000);
    emp[2] = new Employee("Ahmed", 103, 55000);

    cout << "Employee Records\n\n";
    for (int i = 0; i < 3; i++){
        emp[i]->display();
    }
    for (int i = 0; i < 3; i++){
        delete emp[i];
    }
    return 0;
}