/*Build a Person -> Employee -> Manager hierarchy. Person has name and age. Employee adds 
salary and department. Manager adds a bonus percentage and a method that returns total 
compensation (salary + salary * bonus / 100). Each class provides a display() method that 
calls the one above using BaseClass::display(), then adds its own fields.*/
#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) {
        name = n;
        age = a;
    }
    void display() const {
        cout << "Name       : " << name << endl;
        cout << "Age        : " << age << endl;
    }
};
class Employee : public Person {
protected:
    double salary;
    string department;
public:
    Employee(string n, int a, double s, string d) : Person(n, a) {
        salary = s;
        department = d;
    }
    void display() const {
        Person::display();
        cout << "Salary     : " << salary << endl;
        cout << "Department : " << department << endl;
    }
};
class Manager : public Employee {
private:
    double bonusPercentage;
public:
    Manager(string n, int a, double s, string d, double b) : Employee(n, a, s, d) {
        bonusPercentage = b;
    }
    double totalCompensation() const {
        return salary + (salary * bonusPercentage / 100);
    }
    void display() const {
        Employee::display();
        cout << "Bonus (%)  : " << bonusPercentage << "%" << endl;
        cout << "Total Compensation : " << totalCompensation() << endl;
    }
};
int main() {
    Manager m("Awais", 21, 85000, "Software Development", 20);
    cout << "Manager Details\n";
    cout << "---------------\n";
    m.display();
    return 0;
}